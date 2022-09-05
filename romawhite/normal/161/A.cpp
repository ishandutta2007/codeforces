#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=2000000000;
const int mod=1000000007;

int main() {
   int n,m,x,y;
   cin >> n >> m >> x >> y;
   vector<pair<int,int>> a;
   vector<pair<int,int>> b;
   FOR(i,0,n){
       int k;
       cin >> k;
       a.PB(MP(k,i+1));
   }
   FOR(i,0,m){
       int k;
       cin >> k;
       b.PB(MP(k,i+1));
   }
   sort(ALL(a));
   sort(ALL(b));
   vector<pair<int,int>> res;
    for(int i1=0,i2=0;;)
    {
            if (i1>=a.size() || i2>=b.size()) break;
        if (b[i2].first>=a[i1].first-x && b[i2].first<=a[i1].first+y){
            res.PB(MP(a[i1].second,b[i2].second));
            i1++;
            i2++;
        }else{
            if (b[i2].first<a[i1].first-x) i2++;
            else i1++;
        }

    }
    cout << res.size() << endl;
    FOR(i,0,res.size())
        cout << res[i].first << ' ' << res[i].second << endl;
   return 0;
}