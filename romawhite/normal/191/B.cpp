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

bool comp(pair<int,int> a,pair<int,int> b){
    if (a.X > b.X || (a.X == b.X && a.Y < b.Y)) return 1;
    else return 0;
}

bool us[100005];
vector<ll> c;
int main(){
    //freopen("INPUT.TXT","r",stdin);
    //freopen("OUT.TXT","w",stdout);
    int n;
    int k;
    cin >> n >> k;
    ll b;
    cin >> b;
    vector<pair<ll,int> > a(n-1);
    FOR(i,0,n-1){
        cin >> a[i].X;
        a[i].Y = i;
        c.PB(a[i].X);
    }
    sort(a.begin(),a.end(),comp);
    ll M = 0;
    FOR(i,0,k)
        M += a[i].X;
    if (M <= b){
        cout << n;
        return 0;
    }
    ll t = 0;
    memset(us,0,sizeof(us));
    FOR(i,0,k-1){
        t += a[i].X;
        us[a[i].Y] = 1;
    }
    b -= t;
    FOR(i,0,n-1){
        if (us[i]){
            cout << i + 1;
            return 0;
        }
        if (c[i] > b){
            cout << i+1;
            return 0;
        }
    }
    return 0;
}