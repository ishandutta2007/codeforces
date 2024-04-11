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
const int mod=1000000007,MAX=15000005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,M;cin>>N>>M;
    if(N>M) swap(N,M);
    
    if(N==1){
        ll ans=M/6*6;
        M%=6;
        if(M<=3) cout<<ans<<endl;
        else if(M==4) cout<<ans+2<<endl;
        else cout<<ans+4<<endl;
        
        return 0;
    }
    
    if(N==2){
        if(M==2) cout<<0<<endl;
        else if(M==3) cout<<4<<endl;
        else if(M==4) cout<<8<<endl;
        else if(M==5) cout<<10<<endl;
        else if(M==6) cout<<12<<endl;
        else if(M==7) cout<<12<<endl;
        else cout<<2*M<<endl;
        
        return 0;
    }
    
    if(N==3){
        if(M==3) cout<<8<<endl;
        else if(M==4) cout<<12<<endl;
        else if(M==5) cout<<14<<endl;
        else if(M==6) cout<<18<<endl;
        else if(M==7) cout<<20<<endl;
        else if(M==8) cout<<24<<endl;
        else if(M&1) cout<<N*M-1<<endl;
        else cout<<N*M<<endl;
        
        return 0;
    }
    
    if(N%2==0){
        cout<<N*M<<endl;
    }else{
        if(M%2==0) cout<<N*M<<endl;
        else cout<<N*M-1<<endl;
    }
}