//#pragma comment(linker, "/STACK:32777216")
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
using namespace std;

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
const int INF=1000000007;
const LL mod= 1000000007;
const double EPS=1e-7;

int used[100007];
int t = 0;
vector<int> order;
vector<int> g[100007];

vector<int> res;

void dfs(int v){
    if (res.size()) return;
    used[v] = ++t;
    order.PB(v);
    int c = 0;
    int M = INF;
    FOR(i,0,g[v].size())
        if (!used[g[v][i]])
            ++c;
        else M = min(M , used[g[v][i]]);
    if (!c && !res.size()){
        FOR(i,M - 1,order.size())
            res.PB(order[i]);
        return;
    }
    FOR(i,0,g[v].size())
        if (!used[g[v][i]]){
            dfs(g[v][i]);
            break;
        }
}

int main(){
    //freopen("mirrors.in","r",stdin);freopen("mirrors.out","w",stdout);

    int n,m,k;
    cin >> n >> m >> k;
    FOR(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[a].PB(b);
        g[b].PB(a);
    }

    dfs(0);
    cout << res.size() << endl;
    FOR(i,0,res.size())
        cout << res[i] + 1 << ' ';
    cout << endl;

    return 0;
}