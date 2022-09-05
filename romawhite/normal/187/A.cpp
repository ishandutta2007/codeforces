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
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=1000000000;
const ll mod=200907;
const ll N = 1100;
int a[200005],b[200005],f[200005];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    FOR(i,0,n){
        cin >> a[i];
        a[i]--;
    }
    FOR(i,0,n){
        cin >> b[i];
        b[i]--;
        f[b[i]] = i;
    }
    FOR(i,0,n)
        a[i] = f[a[i]];
    int res = -1;
    int M = -1;
    FOR(i,0,n){
        if (a[i] < M) { res = i;break;}
        if (a[i] > M) M = a[i];
    }
    if (res == -1) cout << 0;
    else cout << n - res;
    return 0;
}