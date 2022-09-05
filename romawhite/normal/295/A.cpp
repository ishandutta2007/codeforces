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

struct op{
    int l , r , d;
    op(){}
    op(int L , int R , int D): l(L) , r(R) , d(D){}
};

int main()
{

    //freopen("in.txt","r",stdin);
    int n , m , k;
    cin >> n >> m >> k;
    vector<LL> a(n + 1);
    FOR(i,0,n)
        cin >> a[i];
    RFOR(i,n,1)
        a[i] -= a[i - 1];
    
    vector<op> b(m);

    FOR(i,0,m){
        scanf("%d%d%d" , &b[i].l , &b[i].r , &b[i].d);
    }

    vector<int> c(m + 1 , 0);
    FOR(i,0,k){
        int L , R;
        scanf("%d%d" , &L , &R);
        c[L - 1]++;
        c[R]--;
    }

    int t = 0;

    FOR(i,0,m){
        t += c[i];
        a[b[i].l - 1] += 1ll * t * b[i].d;
        a[b[i].r] -= 1ll * t * b[i].d;
    }

    LL C = 0;
    FOR(i,0,n){
        C += a[i];
        cout << C << ' ';
    }


    return 0;
};