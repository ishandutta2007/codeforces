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

int d[505][505];
int dd[505][505];

int main()
{

    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    FOR(i,0,n)
        FOR(j,0,n)
            scanf("%d" , &dd[i][j]);

    vector<int> x(n);

    FOR(i,0,n)
        cin >> x[i] , x[i]--;

    reverse(ALL(x));

    FOR(i,0,n)
        FOR(j,0,n)
            d[i][j] = dd[x[i]][x[j]];

    vector<LL> res;
    
    for (int k=0; k<n; ++k){
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
        LL r = 0;
        FOR(i,0,k + 1)
            FOR(j,0,k + 1)
                r += d[i][j];
        

        /*cout << endl;
        FOR(i,0,n){
            FOR(j,0,n)
                cout << d[i][j] << ' ';
            cout << endl;
        }
        cout << endl;*/
        
        res.PB(r);
    }

    RFOR(i,res.size() , 0)
        cout << res[i] <<' ';

    return 0;
};