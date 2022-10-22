#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <ctime>
#include <queue>
#include <cmath>
#include <deque>
#include <list>
#include <sstream>
#include <bitset>
#include <complex>
#include <functional>
//#include <unordered_set>
//#include <unordered_map>
//#include <cassert>
#pragma comment(linker, "/STACK:16777216")
#pragma warning(default :4)
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define eps 1e-9
#define INF 1000000001
//#define oo 1000000001
#define oo 0x3F3F3F3F
#define MOD 1000000007
#define cint const int &
#define cll const ll &
#define cull const ull &
#define FOR(i, x) for (int i = 0; i < (int)(x); ++i)
#define CL(x) memset(x, 0, sizeof(x))
#define SINF(x) memset(x, 0x3F, sizeof(x));
#define SVAL(x, y) memset(x, y, sizeof(x))
#define CP(t, f) memcpy(t, f, sizeof(f));
#define FIN freopen("in.txt", "r", stdin);
#define FOUT freopen("out.txt", "w", stdout);
#define y1 ____y1
void dbg() { std::cerr << '\n'; };
template<typename T1> void dbg(T1 x1) { std::cerr << x1 << '\n'; };
template<typename T1, typename T2> void dbg(T1 x1, T2 x2) { std::cerr << x1 << " " << x2 << '\n'; };
template<typename T1, typename T2, typename T3> void dbg(T1 x1, T2 x2, T3 x3) { std::cerr << x1 << " " << x2 << " " << x3 << '\n'; };
const double PI=acos(-1.);
ll Round(double x) { return x<0 ? x-.5 : x+.5; };
using namespace std;
typedef vector<int> VINT;
typedef pair<int, int> PII;
typedef complex<double> Cn;
typedef vector<PII> VPII;
struct Team
{
    string name;
    int score, X, Y, ma;
    Team(string N, int S, int x, int y, int M) : name(N), score(S), X(x), Y(y), ma(M) {};
};
bool operator < (const Team &a, const Team &b)
{
    if (a.score!=b.score) return a.score>b.score;
    if ((a.X-a.Y)!=(b.X-b.Y)) return (a.X-a.Y)>(b.X-b.Y);
    if (a.X!=b.X) return a.X>b.X;
    return a.name<b.name;
}
string BERN="BERLAND", opp;
char s1[111], s2[111];
int c1, c2;
vector<Team> tms;
int gid(string s)
{
    for (int i=0; i<tms.size(); i++)
        if (tms[i].name==s) return i;
    tms.push_back(Team(s, 0, 0, 0, 0));
    return tms.size()-1;
}
void addm(string n1, string n2, int c1, int c2)
{
    int i1=gid(n1), i2=gid(n2);
    if (c1>c2) tms[i1].score+=3;
    if (c1==c2) tms[i1].score+=1, tms[i2].score+=1;
    if (c1<c2) tms[i2].score+=3;
    tms[i1].X+=c1; tms[i1].Y+=c2;
    tms[i2].X+=c2; tms[i2].Y+=c1;
    tms[i1].ma++;
    tms[i2].ma++;
}
int main()
{
    tms.reserve(10);
    FOR(i, 5)
    {
        scanf("%s %s %d:%d\n", s1, s2, &c1, &c2);
        string n1=string(s1, s1+strlen(s1));
        string n2=string(s2, s2+strlen(s2));
        addm(n1, n2, c1, c2);
    }
    for (int i=0; i<tms.size(); i++) if (tms[i].name!=BERN && tms[i].ma<3) opp=tms[i].name;
    for (int d=1; d<200; d++)
        for (int y=0; y<200; y++)
        {
            vector<Team> tmp=tms;
            addm(BERN, opp, y+d, y);
            sort(tms.begin(), tms.end());
            if (gid(BERN)<2)
            {
                printf("%d:%d\n", y+d, y);
                return 0;
            }
            tms=tmp;
        }
    puts("IMPOSSIBLE");
    return 0;
}