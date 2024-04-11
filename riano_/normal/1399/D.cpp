#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll T; cin >> T;
    rep(ii,T){
        ll N; cin >> N;
        string S; cin >> S;
        vector<queue<ll>> ss(2);
        ll j = 1;
        ll lab[N];
        rep(i,N){
            int s = S[i]-'0';
            if(ss[s].empty()){
                lab[i] = j;
                ss[(1-s)].push(j);
                j++;
            }
            else{
                ll k = ss[s].front(); ss[s].pop();
                lab[i] = k;
                ss[(1-s)].push(k);
            }
        }
        cout << j-1 << "\n";
        rep(i,N){
            cout << lab[i] << " ";
        }
        cout << "\n";
    }
    
    //cout << ans << endl;
}