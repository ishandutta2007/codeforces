#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=200005,INF=1<<28;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<ll> pos(70);
    
    int Q;cin>>Q;
    while(Q--){
        int t;cin>>t;
        if(t==1){
            ll x,k;cin>>x>>k;
            ll mo=-1;
            int h=-1;
            for(int i=61;i>=0;i--){
                if(x&(1LL<<i)){
                    mo=(1LL<<i);
                    h=i;
                    break;
                }
            }
            k%=mo;
            if(k<0) k+=mo;
            
            pos[h]+=k;
            pos[h]%=mo;
        }
        if(t==2){
            ll x,k;cin>>x>>k;
            ll mo=-1;
            int h=-1;
            for(int i=61;i>=0;i--){
                if(x&(1LL<<i)){
                    mo=(1LL<<i);
                    h=i;
                    break;
                }
            }
            k%=mo;
            if(k<0) k+=mo;
            
            for(int i=h;i<62;i++,k*=2,mo*=2){
                pos[i]+=k;
                pos[i]%=mo;
            }
        }
        if(t==3){
            ll x;cin>>x;
            ll mo=-1;
            int h=-1;
            for(int i=61;i>=0;i--){
                if(x&(1LL<<i)){
                    mo=(1LL<<i);
                    h=i;
                    break;
                }
            }
            
            ll nowpos=(x-mo+pos[h])%mo;
            
            vector<ll> ans;
            while(1){
                ll y=(1LL<<h);
                y+=nowpos-pos[h];
                if(y<(1LL<<h)) y+=(1LL<<h);
                
                ans.push_back(y);
                
                nowpos/=2;
                mo/=2;
                h--;
                
                if(h==-1) break;
            }
            
            for(ll a:ans) cout<<a<<" ";
            cout<<"\n";
        }
        
    }
}