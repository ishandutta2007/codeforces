#pragma comment(linker, "/STACK:32000000")
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <time.h>
#include <complex>

using namespace std;

#define FOR(i,a,b) for(LL(i)=(a);i<b;i++)
#define RFOR(i,a,b) for(int(i)=(a-1);i>=b;i--)
#define PI acos(-1.0)
#define MP make_pair
#define PB push_back
#define next htrhtrhtrh
#define ALL(A) A.begin(),A.end()
#define SZ(A) A.size()
#define FILL(a,b) memset(a,b,sizeof(a))
#define CLEAR(a) memset(a,0,sizeof(a))

typedef long long Int;
typedef unsigned long long UInt;
typedef long long LL;
typedef unsigned long long ULL;

const int MAX = 200000;
const int INF = 100000000;
const int MOD = 1000000007;
const double EPS = 1E-7;
const int IT = 10024;

vector<int> g[100007];
LL a[100007];
pair<LL,LL> b[100007];
bool used[100007];


void dfs(int v){
    used[v] = 1;
    LL m1 = 0;
    LL m2 = 0;
    FOR(i,0,g[v].size())
        if (!used[g[v][i]]){
            dfs(g[v][i]);
            m1 = max(m1 , b[g[v][i]].first);
            m2 = max(m2 , b[g[v][i]].second);
        }

    int t = a[v] + m1 - m2;
    if (t > 0) m2 += t;
    if (t < 0) m1 -= t;
    b[v] = MP(m1,m2);
    //cout << v << ' ' << m1 << ' ' << m2 << '-' << endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    cin >> n;
    FOR(i,0,n - 1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[a].PB(b);
        g[b].PB(a);
    }

    FOR(i,0,n)
        cin >> a[i];

    dfs(0);
    //FOR(i,0,n)
    //  cout << b[i].first << ' ' << b[i].second << endl;
    cout << b[0].first + b[0].second << endl;

}