#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
 
using namespace std;
 
#define next fdfdsfdsfdsfdsfds
#define y1 ggvfdg
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define FILL(a,b) memset((a),b,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
#define SZ(a) (int)(a).size()
#define y1 asdf
 
typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
 
const long double pi=acos(-1.0);
const int INF=1000000000;
const int MOD = 1000000007;
const double EPS = 1e-7;

set<int> x;
int p[1000007];

int c[1000007];

int nx[1000007];
multiset<int> s;

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    int n;
    cin >> n;
    FOR(i,0,n){
        int xx;
        cin >> xx;
        x.insert(xx);
    }
    int a , b;
    cin >> a >> b;

    FOR(i,0,1000007)
        p[i] = 1;

    for(set<int>::iterator it = x.begin(); it != x.end(); ++it){
        int X = *it;
        for(int i = ((b + X - 1) / X) * X; i <= a; i += X)
            p[i - b] = X - 1;
    }

    FOR(i,0,1000007)
        c[i] = i - 1;

    FOR(i,0,a - b){
        c[min(i + p[i] , a - b)] = min(i , c[min(i + p[i] , a - b)]);
    }

    int T = INF;

    RFOR(i,a - b + 1 , 0){
  
        T = min(T , c[i]);
        
        /*if (i == 640){
            cout << *s.begin() << endl;
        }*/

        nx[i] = T;
    }
    
    //FOR(i,0,a - b + 1)
    //  cout << i + b << ' ' << nx[i] + b << endl;

    int res = 0;
    for(int i = a - b; i != 0; i = nx[i]){
        //cout << i << endl;
        res++;

    }
    cout << res << endl;

    return 0;
}