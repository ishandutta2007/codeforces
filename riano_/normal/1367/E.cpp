#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
using Graph = vector<vector<int>>;

const ll mod = 1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll T; cin >> T;
    rep(ii,T){
        int N,K; 
        cin >> N >> K;
        string S; cin >> S;
        ll cnt[26];
        rep(i,26) cnt[i] = 0;
        rep(i,N){
            cnt[S[i]-'a']++;
        }
        ll ans = 0;
        for(int i=1;i<=K;i++){
            if(K%i!=0) continue;
            ll use[26];
            rep(j,26) use[j] = 0;
            priority_queue<Pr> cand;
            rep(j,26){
                cand.push(make_pair(cnt[j],j));
            }
            rep(j,i){
                Pr p = cand.top(); cand.pop();
                auto[x,k] = p;
                use[k]++;
                cand.push(make_pair(cnt[k]/(use[k]+1),k));
                if(j==i-1){
                    ans = max(ans,i*x);
                }
            }
        }
        cout << ans << "\n";
    }
    
}