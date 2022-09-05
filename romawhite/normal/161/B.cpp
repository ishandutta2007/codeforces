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
    int n,k;
    cin >> n >> k;
    vector <pair<int,int>> a,b;
    FOR(i,0,n){
        int q,w;
        cin >> q >> w;
        if (w==1)
            a.PB(MP(q,i+1));
        else
            b.PB(MP(q,i+1));
    }
    sort(ALL(a));
    sort(ALL(b));
    
    if (a.size()<k){
        double res=0;
        FOR(i,0,a.size())
            res+=double(a[i].first)/2;
        FOR(i,0,b.size())
            res+=double(b[i].first);
        printf("%.1f\n",res);
        FOR(i,0,a.size())
            cout << 1 << ' ' << a[i].second << endl;
        int k1 = k-a.size();
        FOR(i,0,k1-1)
            cout << 1 << ' ' << b[i].second << endl;
        cout << b.size()-k1+1 << ' ';
        FOR(i,k1-1,b.size())
            cout << b[i].second << ' ';
        cout << endl;
        return 0;
    }

    double res=0;
    FOR(i,0,a.size())
        res+=a[i].first;
    FOR(i,0,b.size())
        res+=b[i].first;
    double m=a[0].first;
    if (b.size()>0 && double(b[0].first)<m)
        m =b[0].first;
    res-=m/2;
    FOR(i,0,k-1)
        res-=double(a[a.size()-i-1].first)/2;
    printf("%.1f\n",res);
    FOR(i,0,k-1)
        cout << 1 << ' ' << a[a.size()-i-1].second << endl;
    cout << a.size()+b.size()-k+1 << ' ';
    FOR(i,0,a.size()-k+1)
        cout << a[i].second << ' ';
    FOR(i,0,b.size())
        cout << b[i].second << ' ';
    cout << endl;
   return 0;
}