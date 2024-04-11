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
        int N,M; //cin >> N;
        string S; cin >> S; N = S.size();
        cin >> M;
        ll b[M];
        rep(i,M) cin >> b[i];
        string ans;
        rep(i,M) ans += "A";
        ll cnt[26];
        rep(i,26) cnt[i] = 0;
        rep(i,N){
            cnt[S[i]-'a']++;
        }

        // rep(i,26){
        //     cout << cnt[i] << " ";
        // }
        // cout << "\n";

        int c = 25;
        set<ll> ch;
        while(1){
            vector<ll> zr;
            rep(i,M){
                if(b[i]==0&&!ch.count(i)) zr.push_back(i);
            }
            int u = zr.size();
            //cout << u << "\n";
            while(cnt[c]<u){
                c--;
            }
            for(ll x:zr){
                ans[x] = (char)('a'+c);
                ch.insert(x);
            }
            c--;
            rep(i,M){
                if(ch.count(i)) continue;
                for(ll x:zr){
                    b[i] -= abs(x-i);
                }
            }
            bool comp = true;
            rep(i,M){
                if(ans[i]=='A') comp = false;
            }
            if(comp) break;
        }
        cout << ans << "\n";
    }
    
}