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

Int gcd(Int a,Int b){
    if (!b) return a;
    return gcd(b , a % b);
}

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    int n;
    cin >> n;
    Int r = 0;
    vector<int> a(n);
    FOR(i,0,n){
        cin >> a[i];
        r += abs(a[i]);
    }

    sort(ALL(a));

    Int s = 0;
    FOR(i,1,a.size()){
        s += 1LL * i * (a[i] - a[i - 1]);
        r += 2 * s;
    }

    Int p = n;

    Int g = gcd(r,p);
    cout << r / g << ' ' << p / g << endl;

    return 0;
}