#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 998244353;

int main() {
    ll T; cin >> T;
    rep(ii,T){
        ll N,M,K; cin >> N >> M >> K;
        ll st;
        if(N%2==0) st = 0;
        else{
            st = (N*M)/2;
        }
        string ans = "YES";
        if(abs(st-K)%2!=0) ans = "NO";
        ll sb = (N/2)*(M/2)*2;
        if(st==0){
            if(sb<K) ans = "NO";
        }
        else{
            if((st-sb)>K)  ans = "NO";
        }
        
        cout << ans << endl;
        if(ans=="NO") continue;
        char c[N][M];
        if(N%2==0){
            rep(i,N){
                rep(j,M){
                    char d = (char)('a'+((j%4)+((i/2)%2)*2)%4);
                    c[i][j] = d;
                }
            }
            ll cnt = 0;
            rep(j,M){
                rep(i,N){
                    if(cnt==K/2) break;
                    if((i%2)==1&&(j%2)==0){
                        swap(c[i][j],c[i-1][j+1]); cnt++;
                    }
                    
                    if(cnt==K/2) break;
                }
                if(cnt==K/2) break;
            }
        }
        else{
            rep(i,M){
                rep(j,N){
                    char d = (char)('a'+((j%4)+((i/2)%2)*2)%4);
                    c[j][i] = d;
                }
            }
            ll cnt = 0;
            rep(i,N){
                rep(j,M){
                    if(cnt==(N*M/2-K)/2) break;
                    if((i%2)==1&&(j%2)==0){
                        swap(c[i][j],c[i-1][j+1]); cnt++;
                    }
                    
                    if(cnt==(N*M/2-K)/2) break;
                }
                if(cnt==(N*M/2-K)/2) break;
            }
        }
        rep(i,N){
            rep(j,M){
                cout << c[i][j];
            }
            cout << endl;
        }
    }
    //cout << ans << endl;
}