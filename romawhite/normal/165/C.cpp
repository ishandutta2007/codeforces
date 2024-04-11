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

int dp1[1000005];
ll dp2[1000005];

int main() {
    string s;
    int k;
    cin >> k;
    cin >> s;


    if (s[0]=='1') dp1[0]=1;
    else dp1[0]=0;
    FOR(i,1,s.size())
        if (s[i]=='1')
            dp1[i]=dp1[i-1]+1;
        else dp1[i]=dp1[i-1];
    memset(dp2,0,sizeof(0));
    ll res=0;
    dp2[0]=1;
    FOR(i,0,s.size()){
        if (dp1[i]>=k)
            res+=dp2[dp1[i]-k];
        dp2[dp1[i]]++;
        //cout << res << endl;
    }
    cout << res;
    return 0;
}