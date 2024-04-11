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
const int mod=998244353,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<vector<ll>> cn(2,vector<ll>(2));
    ll s=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>cn[i][j];
            s+=cn[i][j];
        }
    }
    
    if(s==0){
        cout<<0<<"\n";
        return 0;
    }
    
    for(ll a=0;a<=50000;a++){
        if(a*(a-1)/2!=cn[0][0]) continue;
        for(ll b=0;b<=50000;b++){
            if(b*(b-1)/2!=cn[1][1]) continue;
            ll N=a+b;
            if(N*(N-1)/2!=s) continue;
            
            if(cn[0][1]==0){
                for(int i=0;i<b;i++) cout<<1;
                for(int i=0;i<a;i++) cout<<0;
                cout<<"\n";
                return 0;
            }
            if(cn[1][0]==0){
                for(int i=0;i<a;i++) cout<<0;
                for(int i=0;i<b;i++) cout<<1;
                cout<<"\n";
                return 0;
            }
            
            ll rem=cn[1][0];
            string ans;
            while(rem){
                if(rem>a){
                    ans+='1';
                    b--;
                    rem-=a;
                }else{
                    for(int i=0;i<a-rem;i++) ans+='0';
                    ans+='1';
                    b--;
                    for(int i=0;i<rem;i++) ans+='0';
                    for(int i=0;i<b;i++) ans+='1';
                    break;
                }
            }
            cout<<ans<<"\n";
            return 0;
        }
    }
    
    cout<<"Impossible\n";
}