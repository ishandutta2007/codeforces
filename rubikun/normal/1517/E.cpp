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
const int mod=998244353,MAX=250005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N);
        ll sum=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            sum+=A[i];
        }
        
        if(N<=3){
            int ans=0;
            
            for(int bit=0;bit<(1<<N);bit++){
                ll x=0;
                for(int i=0;i<N;i++){
                    if(bit&(1<<i)) x+=A[i];
                }
                if(x<sum-x) ans++;
            }
            
            cout<<ans<<"\n";
            continue;
        }
        
        ll ans=0,pr=0;
        
        for(int i=0;i<=N;i++){
            if(sum-pr<pr) ans++;
            
            if(i==N) break;
            pr+=A[i];
        }
        
        vector<ll> ruiodd(N),ruieven(N),rui(N);
        for(int i=0;i<N;i++){
            if(i){
                ruiodd[i]=ruiodd[i-1];
                ruieven[i]=ruieven[i-1];
                rui[i]=rui[i-1];
            }
            
            rui[i]+=A[i];
            
            if(i&1) ruiodd[i]+=A[i];
            else ruieven[i]+=A[i];
        }
        
        ll lim=(sum-1)/2;
        //0sumlimok
        
        //cout<<ans<<" ";
        
        for(int i=0;i<N-1;i++){
            //[0,i]0
            
            if(i&1){
                ll ok=lim-ruieven[i];
                int d=upper_bound(ruiodd.begin(),ruiodd.end()-1,ok)-ruiodd.begin();
                d--;
                
                ans+=max(0,(d-i+2)/2);
                
                if(i==N-2) continue;
                
                ok-=A[N-1];
                d=upper_bound(ruiodd.begin(),ruiodd.end()-2,ok)-ruiodd.begin();
                d--;
                
                ans+=max(0,(d-i+2)/2);
            }else{
                ll ok=lim-ruiodd[i];
                int d=upper_bound(ruieven.begin(),ruieven.end()-1,ok)-ruieven.begin();
                d--;
                
                ans+=max(0,(d-i+2)/2);
                
                if(i==N-2) continue;
                
                ok-=A[N-1];
                d=upper_bound(ruieven.begin(),ruieven.end()-2,ok)-ruieven.begin();
                d--;
                
                ans+=max(0,(d-i+2)/2);
            }
            
        }
        
        for(int i=1;i<N-1;i++){
            //[1,i]0
            
            if(i&1){
                ll ok=lim-ruieven[i]+A[0];
                int d=upper_bound(ruiodd.begin(),ruiodd.end()-1,ok)-ruiodd.begin();
                d--;
                
                ans+=max(0,(d-i+2)/2);
                
                if(i==N-2) continue;
                
                ok-=A[N-1];
                d=upper_bound(ruiodd.begin(),ruiodd.end()-2,ok)-ruiodd.begin();
                d--;
                
                ans+=max(0,(d-i+2)/2);
            }else{
                ll ok=lim-ruiodd[i]+A[0];
                int d=upper_bound(ruieven.begin(),ruieven.end()-1,ok)-ruieven.begin();
                d--;
                
                ans+=max(0,(d-i+2)/2);
                
                if(i==N-2) continue;
                
                ok-=A[N-1];
                d=upper_bound(ruieven.begin(),ruieven.end()-2,ok)-ruieven.begin();
                d--;
                
                ans+=max(0,(d-i+2)/2);
            }
            
            //cout<<ans<<" ";
        }
        
        ans%=mod;
        
        cout<<ans<<"\n";
        
    }
    
    
}