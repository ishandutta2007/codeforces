#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 1000000007;


//C C[i][j]iCj
void combination(vector<vector <long long> > &v){
    for(int i = 0;i <v.size(); i++){
        v[i][0]=1;
        v[i][i]=1;
    }
    for(int k = 1;k <v.size();k++){
        for(int j = 1;j<k;j++){
          v[k][j]=(v[k-1][j-1]+v[k-1][j])%mod;
        }
    }
}
    

int main() {
    ll N; cin >> N;
    //main K
    ll K = 1500;
    vector<vector<long long>> C(K,vector<long long int>(K,0));
    combination(C);
    rep(ii,N){
        ll n,k; cin >> n >> k;
        vector<ll> a;
        rep(i,n){
            ll b; cin >> b; a.push_back(b);
        }
        sort(a.begin(),a.end()); reverse(a.begin(),a.end());
        ll st = a[k-1];
        ll l = 0,m = 0;
        rep(i,n){
            if(a[i]>st) m++;
            else if(a[i]==st) l++;
        }
        ll ans = C[l][k-m];
        cout << ans << endl;
    }
    //cout << ans << endl;
}