#include <iostream>
#include <set>
#define INF (1LL << 50)
using namespace std;

typedef long long ll;

ll N, S, L, v[100005];
ll dp[100005];

set<pair<ll, ll> > strip, dpelt;

bool fine(){
    ll low = strip.begin()->first;
    ll high = (--strip.end())->first;
    return (high-low)<=S;
}

int main(){
    cin >> N >> S >> L;
    for(ll i=0; i<N; i++)
        cin >> v[i];

    ll i=0;
    dp[0] = 0;

    for(ll k=0; k<N; k++){
        strip.insert(make_pair(v[k], k));
        while(!fine()){
            dpelt.erase(make_pair(dp[i], i));
            strip.erase(make_pair(v[i], i));
            i++;
        }
        if(k-L+1 >= i) dpelt.insert(make_pair(dp[k-L+1], k-L+1));
        
        if(dpelt.size())
            dp[k+1] = min(INF, 1 + dpelt.begin()->first);
        else dp[k+1] = INF;
    }

    if(dp[N] == INF) cout << -1 << endl;
    else cout << dp[N] << endl;
    return 0;
}