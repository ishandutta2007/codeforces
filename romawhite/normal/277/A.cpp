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

vector<int> g[105];
vector<int> a[105];
int n,m;
bool used[107];

int res = 0;

void dfs(int v){
    used[v] = 1;
    FOR(i,0,g[v].size())
        if (!used[g[v][i]])
            dfs(g[v][i]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    cin >> n >> m;
    bool q = 0;
    FOR(i,0,n){
        int k;
        cin >> k;
        if(k) q = 1;
        a[i].resize(k);
        FOR(j,0,k)
            cin >> a[i][j];
    }

    if (!q){
        cout << n << endl;
        return 0;
    }

    set<int> s;

    FOR(i,0,n)
        FOR(j,i + 1, n){
            s.clear();
            FOR(k,0,a[i].size())
                s.insert(a[i][k]);
            FOR(k,0,a[j].size())
                s.insert(a[j][k]);
            if (s.size() < a[i].size() + a[j].size())
                g[i].PB(j) , g[j].PB(i);
    }


    FOR(i,0,n)
        if (!used[i]){
            ++res;
            dfs(i);
        }

    cout << res - 1<< endl;

}