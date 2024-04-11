#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))

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
const double MY_PI = acos(-1.0);

// ========================================================================= //

typedef complex < double > comp;
const int N = 1 << 19;

class SegTree
{
    vector < comp > tadd, tmul;

    void push(int c)
    {
        int c1 = c * 2 + 1;
        int c2 = c * 2 + 2;

        tmul[c1] *= tmul[c];
        tadd[c1] *= tmul[c];
        tadd[c1] += tadd[c];
        tmul[c2] *= tmul[c];
        tadd[c2] *= tmul[c];
        tadd[c2] += tadd[c];

        tadd[c] = 0.0;
        tmul[c] = 1.0;
    }

public:
    void init(int n)
    {
        tadd.resize(N*2-1);
        tmul.resize(N*2-1);
        for (int i = 0; i < N*2-1; ++i)
            tmul[i] = 1.0;
        for (int i = 0; i < n; ++i)
            tadd[N-1+i] = i + 1.0;
    }

    void add(int l, int r, comp val, int c = 0, int cl = 0, int cr = N - 1)
    {
        if (cl > r || cr < l)
            return;
        if (l <= cl && cr <= r)
        {
            tadd[c] += val;
            return;
        }
        push(c);
        int mid = (cl + cr) / 2;
        add(l, r, val, c*2+1, cl, mid);
        add(l, r, val, c*2+2, mid+1, cr);
    }

    void mul(int l, int r, comp val, int c = 0, int cl = 0, int cr = N - 1)
    {
        if (cl > r || cr < l)
            return;
        if (l <= cl && cr <= r)
        {
            tmul[c] *= val;
            tadd[c] *= val;
            return;
        }
        push(c);
        int mid = (cl + cr) / 2;
        mul(l, r, val, c*2+1, cl, mid);
        mul(l, r, val, c*2+2, mid+1, cr);
    }

    comp get(int v, int c = 0, int cl = 0, int cr = N - 1)
    {
        if (cl == cr)
            return tadd[c];
        push(c);
        int mid = (cl + cr) / 2;
        if (v <= mid)
            return get(v, c*2+1, cl, mid);
        else
            return get(v, c*2+2, mid+1, cr);
    }
} st;

int n, m;

int main()
{
    ios::sync_with_stdio(false);

    scanf("%d%d", &n, &m);
    st.init(n);
    for (int i = 0; i < m; ++i)
    {
        int type, seg;
        double y;
        scanf("%d%d%lf", &type, &seg, &y);
        --seg;
        if (type == 1)
        {
            comp vec = st.get(seg);
            if (seg != 0)
                vec -= st.get(seg - 1);
            vec /= abs(vec);
            st.add(seg, n - 1, vec * y);
        } else
        {
            comp center = (seg == 0 ? comp(0.0) : st.get(seg - 1));
            st.add(seg, n - 1, -center);
            st.mul(seg, n - 1, polar(1.0, -y*MY_PI/180.0));
            st.add(seg, n - 1, center);
        }

        comp x = st.get(n - 1);
        printf("%.5lf %.5lf\n", real(x), imag(x));
    }

    return 0;
}