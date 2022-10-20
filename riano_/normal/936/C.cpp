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
    ll N; cin >> N;
    string S,T; cin >> S >> T;
    ll cnt[26];
    rep(i,26) cnt[i] = 0;
    rep(i,S.size()){
        cnt[(S[i]-'a')]++;
    }
    rep(i,T.size()){
        cnt[(T[i]-'a')]--;
    }
    rep(i,26){
        if(cnt[i]!=0){
            cout << -1 << endl; return 0;
        }
    }
    vector<ll> ans;
    int sz = 0; int pt = 0;
    rep(i,T.size()){
        char c = T[i];
        
        sz = i;
        if(i%2==0){
            //cout << N-sz << " ";
            ans.push_back(N-sz);
            string u1 = S.substr(0,sz);
            string u2 = S.substr(sz,N-sz);
            reverse(u2.begin(),u2.end());
            //reverse(u1.begin(),u1.end());
            S = u2 + u1; ll x;
            rep(j,S.size()){
                if(S[j]==c){
                    x = N-(j+1); break;
                }
            }
            //cout << x << " ";
            ans.push_back(x);
            u1 = S.substr(0,N-x);
            u2 = S.substr(N-x,x);
            reverse(u2.begin(),u2.end());
            //reverse(u1.begin(),u1.end());
            S = u2 + u1;
            ans.push_back(1); x = 1;
            //cout << x << " ";
            u1 = S.substr(0,N-x);
            u2 = S.substr(N-x,x);
            reverse(u2.begin(),u2.end());
            //reverse(u1.begin(),u1.end());
            S = u2 + u1;
        }
        else{
            ll x;
            string u1;
            string u2;
            rep(j,S.size()){
                if(j<i) continue;
                if(S[j]==c){
                    x = N-(j); break;
                }
            }
            //if(i==3) cout << "-----" << endl;
            ans.push_back(x);
            //cout << x << " ";
            u1 = S.substr(0,N-x);
            u2 = S.substr(N-x,x);
            reverse(u2.begin(),u2.end());
            //reverse(u1.begin(),u1.end());
            S = u2 + u1;
            //if(i==3) cout << S << endl;
            x = N-x-sz;
            ans.push_back(x);
            //cout << x << " ";
            //if(i==3) cout << "-----" << endl;
            u1 = S.substr(0,N-x);
            u2 = S.substr(N-x,x);
            reverse(u2.begin(),u2.end());
            //reverse(u1.begin(),u1.end());
            S = u2 + u1;
            x = N;
            ans.push_back(x);
            //cout << x << " ";
            u1 = S.substr(0,N-x);
            u2 = S.substr(N-x,x);
            reverse(u2.begin(),u2.end());
            //reverse(u1.begin(),u1.end());
            S = u2 + u1;
        }
        //cout << S << endl;
    }
    if(S!=T) ans.push_back(N);
    cout << ans.size() << endl;
    for(ll x:ans){
        cout << x << " ";
    }
    cout << endl;
    
    //cout << ans << endl;
}