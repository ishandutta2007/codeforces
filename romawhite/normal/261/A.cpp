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

int q[100007];
int a[100007];
int s[100007];

int sum(int l , int r){
    if (l > r) return 0;
    if (!l) return s[r];
    else return s[r] - s[l - 1];
}

int dp[100007];

int main(){
    //freopen("mirrors.in","r",stdin);freopen("mirrors.out","w",stdout);

    int m;
    cin >> m;
    FOR(i,0,m){
        cin >> q[i];
    }
    
    int n;
    cin >> n;
    FOR(i,0,n){
        cin >> a[i];
    }
    
    sort(q , q + m);
    sort(a, a + n);

    reverse(a , a + n);
    int x = q[0] + 2;

    int res = 0;

    FOR(i,0,n)
        if (i % x != x - 1 && i % x != x - 2)
            res += a[i];

    cout << res << endl;

    return 0;
}