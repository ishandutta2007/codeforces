//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#define _CRT_SECURE_NO_DEPRECATE
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory>
#include<memory.h>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef unsigned long long      ui64;
typedef long long               LL;
typedef vector<int>             VI;
typedef vector<bool>            VB;
typedef vector<VI>              VVI;
typedef vector<string>          VS;
typedef pair<int,int>           PII;
typedef map<string,int>         MSI;
typedef set<int>                SI;
typedef set<string>             SS;
typedef map<int,int>            MII;
typedef pair<double,double>     PDD;

#define PB                      push_back
#define MP                      make_pair
#define X                       first
#define Y                       second
#define FOR(i, a, b)            for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)           for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b)             memset(a, b, sizeof(a))
#define SZ(a)                   int((a).size())
#define ALL(a)                  (a).begin(), (a).end()
#define RALL(a)                 (a).rbegin(), (a).rend()
#define INF                     (2000000000)
#define FILL                    CLEAR

const int MAX = 64;
const int MOD = 1000000007;

vector<int> ttt;
int c;
LL dp[55][55][2];
int k = 0 , l = 0;

struct state{
    int i;
    int j;
    bool q;
    state(){}
    state(int I , int J , bool Q) : i(I) , j(J) , q(Q){}
    
    int toint(){
        return 110 * i + 2 * j + q;
    }

};

state tost(int t){
    state T;
    T.q = t & 1;
    t /= 2;
    T.j = t % 55;
    T.i = t / 55;
    return T;
}

vector<int> g[10000];
vector<pair<int , LL> > gr[10000];

LL C[100][100];

int main()
{
    //freopen("in.txt","r",stdin);

    C[0][0] = 1;
    FOR(i,1,100)
        FOR(j,0,i + 1){
            if (j == 0 || j == i)
                C[i][j] = 1;
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }

    int n;
    cin >> n >> c;
    c /= 50;
    FOR(i,0,n){
        int t;
        cin >> t;
        if (t == 50) ++k;
        else ++l;
    }


    FOR(i,0,k+1)
        FOR(j,0,l + 1)
            FOR(q,0,2){
                state v(i , j , q);
                if (q == 0){
                    FOR(i1,0,i + 1)
                        FOR(j1,0,j + 1)
                            if (i1 + j1 && i1 + 2 * j1 <= c){
                                state to(i - i1 , j - j1 , 1);
                                g[v.toint()].PB(to.toint());
                                
                                gr[to.toint()].PB(MP(v.toint() , (C[i][i1] * C[j][j1]) % MOD ));
                            }
                }
                if (q == 1){
                    FOR(i1,0,k - i + 1)
                        FOR(j1,0,l - j + 1)
                            if (i1 + j1 && i1 + 2 * j1 <= c){
                                state to(i + i1 , j + j1 , 0);
                                g[v.toint()].PB(to.toint());

                                gr[to.toint()].PB(MP(v.toint() , (C[k - i][i1] * C[l - j][j1]) % MOD ));
                            }
                }
    }

    int s = state(k , l , 0).toint();
    int f = state(0 , 0 , 1).toint();

    queue<int> q;
    q.push (s);
    vector<bool> used (7000);
    vector<int> d (7000 , INF);
    used[s] = true;
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                d[to] = d[v] + 1;
            }
        }
    }

    if (d[f] >= INF){
        cout << -1 << endl << 0 << endl;
        return 0;
    }

    cout << d[f] << endl;

    queue<int> qq;
    qq.push (f);
    FOR(i,0,7000)
        used[i] = 0;
    vector<LL> res(7000 , 0);
    used[f] = true;
    res[f] = 1;
    while (!qq.empty()) {
        int v = qq.front();
        qq.pop();
        for (size_t i=0; i<gr[v].size(); ++i) {
            int to = gr[v][i].first;
            if (d[to] == d[v] - 1)
                    res[to] += res[v] * gr[v][i].second;
            res[to] %= MOD;
            if (!used[to]) {
                used[to] = true;
                qq.push(to);
            }
        }
    }

    /*FOR(i,0,k + 1)
        FOR(j,0,l + 1)
            FOR(q , 0 , 2)
            cout << i << ' ' << j << ' ' << q  << "      " <<res[state(i , j , q).toint()] << endl;
    */cout << res[s] << endl;

    return 0;
};