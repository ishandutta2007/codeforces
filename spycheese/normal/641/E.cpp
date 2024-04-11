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
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 1000179;

int ans[N];
int nn = 0;

struct Num
{
    struct Que
    {
        int a, t, num;
    };
    vector < Que > qq;

    void solve()
    {
        vector < int > allT;
        for (const auto & q : qq)
            allT.push_back(q.t);
        sort(allT.begin(), allT.end());
        for (auto & q : qq)
            q.t = lower_bound(allT.begin(), allT.end(), q.t) - allT.begin();
        static int fen[N];
        for (const auto & q : qq)
        {
            if (q.a == 3)
            {
                int ss = 0;
                int pos = q.t;
                for (; pos >= 0; pos = (pos&(pos+1)) - 1)
                    ss += fen[pos];
                ans[q.num] = ss;
            } else {
                int val = (q.a == 1 ? 1 : -1);
                int pos = q.t;
                for (; pos < N; pos |= pos + 1)
                    fen[pos] += val;
            }
        }
        for (const auto & q : qq)
        {
            if (q.a != 3)
            {
                int pos = q.t;
                for (; pos < N; pos |= pos + 1)
                    fen[pos] = 0;
            }
        }
    }
};

unordered_map < int , Num > nums;

int main()
{
    ios::sync_with_stdio(false);

    int sq;
    scanf("%d", &sq);
    for (int i = 0; i < sq; ++i)
    {
        int a, t, x;
        scanf("%d%d%d", &a, &t, &x);
        nums[x].qq.push_back({a, t, (a == 3 ? (nn++) : -1)});
    }

    for (auto nm : nums)
        nm.second.solve();

    for (int i = 0; i < nn; ++i)
        printf("%d\n", ans[i]);

    return 0;
}