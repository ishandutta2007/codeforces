#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
#include <time.h>
#include <sstream>
#include <stack>
using namespace std;

#define next gdfsgvd
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
#define FILL(a,value) memset(a,value,sizeof(a))

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

const double pi = acos(-1.0);
const LL INF=1000000000;
const LL mod= 1000000007;
const double EPS = 1e-7;

int a[200007];
map<pair<int,int> , int > M;
vector<pair<int, int> > g[200007];
vector<pair<int,int> > e;
int n,m;
bool used[200007];

void dfs(int v){
    used[v] = 1;
    FOR(i,0,g[v].size())
        if (!used[g[v][i].first]){
            M[MP(v , g[v][i].first)] = 0;
            M[MP(g[v][i].first , v)] = 1;
            a[g[v][i].first] -= 2 * g[v][i].second;
            if (a[g[v][i].first] == 0)
                dfs(g[v][i].first);
        }
}

int main(){
    cin >> n >> m;
    FOR(i,0,m){
        int k,l,c;
        cin >> k >> l >> c;
        --k;--l;
        e.PB(MP(k,l) );
        a[k] += c;
        a[l] += c;
        g[k].PB(MP(l,c));
        g[l].PB(MP(k,c));
    }
    a[n - 1] = INF + 747474744;

    dfs(0);
    
    FOR(i,0,e.size())
        cout << M[MP(e[i].first , e[i].second)] << endl;

    return 0;
}