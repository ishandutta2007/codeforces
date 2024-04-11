#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define LL long long
#define LD long double
#define VPII vector<PII>
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " =", (x), " "
const int M = 1024;

int n, k, l;
char C[M][M];
vector<char> V;

int32_t main()
{
    scanf("%d%d%d ", &n, &l, &k);
    FOR(i, 1, n * l)
    {
        char c;
        scanf("%c", &c);
        V.PB(c);
    }
    sort(ALL(V));
    int p = 1, tmp = 0;
    FOR(i, 1, l)
    {
        char prv = V[tmp];
        int ind = p;
        debug(i, p, k);
        FOR(j, p, k)
        {
            C[j][i] = V[tmp];
            if (V[tmp] != prv)
            {
                prv = V[tmp];
                ind = j;
            }
            tmp++;
        }
        p = ind;
    }
    debug(tmp);
    FOR(i, 1, n)
    {
        FOR(j, 1, l)
        {
            if (C[i][j] == 0)
            {
                C[i][j] = V[tmp];
                tmp++;
            }
        }
        printf("%s\n", C[i] + 1);
    }
}