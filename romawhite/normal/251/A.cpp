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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

const double pi = acos(-1.0);
const int INF=1000000000;
const LL mod= 1000000007;

int main(){
    //freopen("in.txt", "r" , stdin);
    int n;
    int d;
    cin >> n >> d;
    vector<int> a(n);
    FOR(i,0,n)
        cin >> a[i];

    int j = 0;
    LL res = 0;
    FOR(i,0,n){
        while (j < n && a[j] - a[i] <= d){
            ++j;
        }
        res += 1ll * (j - i - 1) * (j - i - 2) / 2;
    }

    cout << res << endl;

    return 0;
}