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

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 105
#define MX 60005
int n, r;
pii pro[MN];
int dp[MX];
vpii bad;

bool comp(pii a, pii b){
    if(a.f+a.s != b.f+b.s){
        return a.f+a.s > b.f+b.s;
    }
    return a.f > b.f;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -0x3f, sizeof dp);

    cin >> n >> r;
    F0R(i, n){
        cin >> pro[i].f >> pro[i].s;
    }
    int cnt = 0;
    sort(pro, pro+n);
    F0R(i, n){
        if(pro[i].s < 0){
            bad.pb(pro[i]);
            continue;
        }
        if(pro[i].f <= r){
            ++cnt;
            r += pro[i].s;
        }
    }
    int mx = cnt;
    dp[r] = cnt;
    //cout << cnt << " " << r << "\n";
    sort(bad.begin(), bad.end(), comp);
    for(auto u : bad){
        //cout << "proc " << u.f << " " << u.s << "\n";
        F0R(i, r){
            if(i < u.f+u.s) continue;
            dp[i] = max(dp[i], dp[i-u.s]+1);
            if(mx < dp[i]){
                mx = dp[i];
                //cout << "new mx at " << i << "\n";
            }
            //mx = max(mx, dp[i]);
        }
    }

    cout << mx << "\n";

    return 0;
}