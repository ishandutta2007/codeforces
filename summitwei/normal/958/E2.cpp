#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MC 80
#define MN 500005
int n, k;
int tim[MN];

pair<double, int> dp[MN];
pii mx[MN];
void getDP(double x){
    FOR(i, 2, n){
        int d = tim[i]-tim[i-1];
        double o = dp[i-2].f+d-x;
        
        if(o < dp[i-1].f){
            dp[i] = mp(o, dp[i-2].s+1);
            if(mx[i-2].f < d) mx[i] = mp(d, 1);
            else if(mx[i-2].f==d) mx[i] = mp(mx[i-2].f, mx[i-2].s+1);
            else mx[i] = mx[i-2];
        } else{
            dp[i] = dp[i-1];
            mx[i] = mx[i-1];
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> n;
    FOR(i, 1, n){
        cin >> tim[i];
    }
    
    sort(tim+1, tim+n+1);
    
    double l = 0;
    double r = INF;
    double mid = (l+r)/2;
    getDP(mid);
    int cnt = 0;
    
    double mn = INF;
    while(cnt <= MC){
        //cout << mid << " has score " << val.f << " using " << val.s << "\n";
        if(dp[n].s > k){
            r = mid;
        } else{
            l = mid;
        }
        
        if(dp[n].s>=k && dp[n].s-mx[n].s < k){
            mn = min(mn, dp[n].f+mid*dp[n].s-mx[n].f*(dp[n].s-k));
        }
        
        mid = (l+r)/2;
        getDP(mid);
        cnt++;
    }
    
    cout << fixed << setprecision(0) << mn << "\n";

    return 0;
}