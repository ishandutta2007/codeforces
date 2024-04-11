#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }

// ========================================================================= //

const int N = 1 << 17;

class SegTree
{
    struct Node
    {
        ll sum = 0;
        ll sumd[10];
        int ch[10];
        bool hch;
        Node()
        {
            for (int i = 0; i < 10; ++i)
                ch[i] = i;
        };
        void apply(int x, int y)
        {
            hch = 1;
            for (int i = 0; i < 10; ++i)
                if (ch[i] == x)
                    ch[i] = y;
            sum -= sumd[x]*x;
            sum -= sumd[y]*y;
            sumd[y] += sumd[x];
            sumd[x] = 0;
            sum += sumd[y]*y;
        }
        void apply(int const * nch)
        {
            hch = 1;
            ll nsumd[10];
            memset(nsumd, 0, sizeof(nsumd));
            for (int i = 0; i < 10; ++i)
                nsumd[nch[i]] += sumd[i];
            memcpy(sumd, nsumd, sizeof(long long) * 10);
            sum = 0;
            for (int i = 1; i < 10; ++i)
                sum += sumd[i] * i;
            for (int i = 0; i < 10; ++i)
                ch[i] = nch[ch[i]];
        }
    };
    Node t[N*2 - 1];

    void push(int c)
    {
        Node & v = t[c];
        if (!v.hch)
            return;
        Node & v1 = t[c*2+1];
        Node & v2 = t[c*2+2];
        v1.apply(v.ch);
        v2.apply(v.ch);
        v.hch = 0;
        for (int i = 0; i < 10; ++i)
            v.ch[i] = i;
    }
public:
    void init(int n, int * a)
    {
        for (int i = 0; i < n; ++i)
        {
            Node & v = t[N - 1 + i];
            v.sum = a[i];
            int b = a[i];
            ll t10 = 1;
            while (b)
            {
                int d = b % 10;
                v.sumd[d] += t10;
                b /= 10;
                t10 *= 10;
            }
        }
        for (int i = N - 2; i >= 0; --i)
        {
            Node & v = t[i];
            const Node & v1 = t[i*2+1];
            const Node & v2 = t[i*2+2];
            v.sum = v1.sum + v2.sum;
            for (int j = 0; j < 10; ++j)
                v.sumd[j] = v1.sumd[j] + v2.sumd[j];
        }
    }

    ll getSum(int l, int r, int c = 0, int cl = 0, int cr = N - 1)
    {
        if (l > cr || r < cl)
            return 0;
        if (l <= cl && cr <= r)
            return t[c].sum;
        push(c);
        return getSum(l, r, c*2+1, cl, (cl+cr)/2) + getSum(l, r, c*2+2, (cl+cr)/2+1, cr);
    }

    void change(int l, int r, int x, int y, int c = 0, int cl = 0, int cr = N - 1)
    {
        if (l > cr || r < cl)
            return;
        if (l <= cl && cr <= r)
        {
            t[c].apply(x, y);
            return;
        }
        push(c);
        change(l, r, x, y, c*2+1, cl, (cl+cr)/2);
        change(l, r, x, y, c*2+2, (cl+cr)/2+1, cr);
        t[c].sum = t[c*2+1].sum + t[c*2+2].sum;
        t[c].sumd[x] = t[c*2+1].sumd[x] + t[c*2+2].sumd[x];
        t[c].sumd[y] = t[c*2+1].sumd[y] + t[c*2+2].sumd[y];
    }
} st;

int main()
{
    ios::sync_with_stdio(false);
    int n, q;
    scanf("%d%d", &n, &q);
    static int a[N];
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    st.init(n, a);
    for (int i = 0; i < q; ++i)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int l, r, x, y;
            scanf("%d%d%d%d", &l, &r, &x, &y);
            --l;
            --r;
            if (x == y)
                continue;
            st.change(l, r, x, y);
        } else 
        {
            int l, r;
            scanf("%d%d", &l, &r);
            --l;
            --r;
            cout << st.getSum(l, r) << "\n";
        }
    }

    return 0;
}