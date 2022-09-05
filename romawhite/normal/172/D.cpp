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
const int N = 10000005;
int p[N];
int d[N];
int main() {
    int a,n;
    cin >> a >> n;
    int N1 = a+n;
    CLEAR(p);
    p[1] = 1;
    for(int i = 2; i*i <= N1; ++i)
        if (p[i] == 0)
            for(int j = i*i; j<=N1; j+=i){
                if (p[j]==0)
                    p[j] = i;
            }
    FOR(i,1,N1)
        if (p[i] == 0)
            p[i] = i;
    CLEAR(d);
    d[1] = 1;
    FOR(i,2,N1){
        int j = i;
        ll k = 1;
        ll pp = (ll)p[i]*p[i];
        while (j%p[i] == 0){
            if (ll(j)%pp == 0){
                j/=pp;
                k*=pp;
            }
            else j/=p[i];
        }
        d[i] = k*d[j];
    }
    ll res = 0;
    FOR(i,a,a+n)
        res += ll(i)/d[i];
    cout << res; 
    return 0;
}