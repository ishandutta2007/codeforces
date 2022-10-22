#include <functional>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> P;

template <typename T>
struct SegmentTree
{
    using F = function<T(T, T)>;

    const F f;
    const T e;

    int n;
    vector<T> seg;

    SegmentTree(int nn, const F f, const T e) : f(f), e(e)
    {
        n = 1;
        while (n <= nn)
            n <<= 1;
        seg.assign(n * 2, e);
    }

    void set(int i, T x)
    {
        seg[i + n] = x;
    }

    void build()
    {
        for (int k = n - 1; k > 0; k--)
        {
            seg[k] = f(seg[k * 2], seg[k * 2 + 1]);
        }
    }

    void update(int i, T x)
    {
        int k = i + n;
        seg[k] = x;
        while (k >>= 1)
        {
            seg[k] = f(seg[k * 2], seg[k * 2 + 1]);
        }
    }

    T query(int l, int r)
    {
        l += n, r += n;
        T L = e, R = e;
        for (; l != r; l >>= 1, r >>= 1)
        {
            if (l % 2)
                L = f(L, seg[l++]);
            if (r % 2)
                R = f(seg[--r], R);
        }
        return f(L, R);
    }

    T operator[](const int i) const
    {
        return seg[i + n];
    }

    template <typename C>
    int right_bound_sub(int k, const C &check, T x)
    {
        while (k < n)
        {
            if (check(f(x, seg[k * 2])))
            {
                k = k * 2;
            }
            else
            {
                x = f(x, seg[k * 2]);
                k = k * 2 + 1;
            }
        }
        return k - n;
    }

    template <typename C>
    int right_bound(int i, const C &check)
    {
        T x = e;
        for (int l = i + n, r = n * 2; l != r; l >>= 1, r >>= 1)
        {
            if (l % 2)
            {
                if (check(f(x, seg[l])))
                {
                    return right_bound_sub(l, check, x);
                }
                x = f(x, seg[l]);
                l++;
            }
        }
        return -1;
    }

    template <typename C>
    int left_bound_sub(int k, const C &check, T x)
    {
        while (k < n)
        {
            if (check(f(seg[k * 2 + 1], x)))
            {
                k = k * 2 + 1;
            }
            else
            {
                x = f(seg[k * 2 + 1], x);
                k = k * 2;
            }
        }
        return k - n;
    }

    template <typename C>
    int left_bound(int i, const C &check)
    {
        T x = e;
        for (int l = n, r = i + n; l != r; l >>= 1, r >>= 1)
        {
            if (r % 2)
            {
                if (check(f(seg[--r], x)))
                {
                    return left_bound_sub(r, check, x);
                }
                x = f(x, seg[r]);
            }
        }
        return -1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[300005];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
        }
        int up[300005], dw[300005];
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (st.size())
            {
                if (a[i] < a[st.top()])
                {
                    break;
                }
                up[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (st.size())
        {
            up[st.top()] = n;
            st.pop();
        }
        for (int i = 0; i < n; i++)
        {
            while (st.size())
            {
                if (a[i] > a[st.top()])
                {
                    break;
                }
                dw[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (st.size())
        {
            dw[st.top()] = n;
            st.pop();
        }
        SegmentTree<P> segmax(n, [](P a, P b){return max(a, b);}, P(-1, -1));
        SegmentTree<P> segmin(n, [](P a, P b){return min(a, b);}, P(n, -1));
        for(int i = 0; i < n; i++)
        {
            segmax.set(i, P(a[i], i));
            segmin.set(i, P(a[i], i));
        }
        segmax.build();
        segmin.build();
        int ans = 0;
        int i = 0;
        while(i < n - 1)
        {
            if(a[i] < a[i + 1])
            {
                i = segmax.query(i, dw[i]).second;
            }
            else
            {
                i = segmin.query(i, up[i]).second;
            }
            ans++;
        }
        cout << ans << "\n";
    }
}