#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 1000000007;

int main() {
    ll N; cin >> N;
    rep(ii,N){
        ll n; cin >> n;
        string ans = "YES";
        ll a[n][n],b[n][n];
        rep(i,n){
            rep(j,n){
                char c;
                cin >> c;
                a[i][j] = (int)(c-'0');
            }
        }
        rep(i,n){
            rep(j,n){
                char c;
                cin >> c;
                b[i][j] = (int)(c-'0'); b[i][j] ^= a[i][j];
            }
        }
        rep(i,n-1){
            rep(j,n-1){
                ll cnt = 0;
                rep(k,2){
                    rep(l,2){
                        cnt += b[i+k][l+j];
                    }
                }
                if(cnt%2!=0) ans = "NO";
            }
        }
        cout << ans << endl;
    }
    //cout << ans << endl;
}