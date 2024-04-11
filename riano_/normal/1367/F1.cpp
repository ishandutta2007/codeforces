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
        int N; 
        cin >> N;
        vector<Pr> p;
        rep(i,N){
            ll b; cin >> b; p.push_back(make_pair(b,i));
        }
        sort(p.begin(),p.end());
        vector<ll> perm(N);
        rep(i,N){
            perm[i] = p[i].second;
        }
        ll cn = 0,prev = -1;
        ll cm = 0;
        rep(i,N){
            if(perm[i]>prev){
                cn++; cm = max(cm,cn);
            }
            else cn = 1;
            prev = perm[i];
        }
        ll ans = N-cm;
        cout << ans << "\n";
    }
    
}