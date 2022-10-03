#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    
    for(int i=0;i<T;i++){
        string S;cin>>S;
        int N=int(S.size());
        vector<ll> h(N+1,0),w(N+1,0),hmax1(N+1,0),hmin1(N+1,0),wmax1(N+1,0),wmin1(N+1,0);
        vector<ll> hmax2(N+1,0),hmin2(N+1,0),wmax2(N+1,0),wmin2(N+1,0);
        for(int j=0;j<N;j++){
            
            h[j+1]=h[j];
            w[j+1]=w[j];
            
            if(S[j]=='W') h[j+1]=h[j]+1;
            if(S[j]=='S') h[j+1]=h[j]-1;
            if(S[j]=='A') w[j+1]=w[j]-1;
            if(S[j]=='D') w[j+1]=w[j]+1;
            
            hmax1[j+1]=max(hmax1[j],h[j+1]);
            hmin1[j+1]=min(hmin1[j],h[j+1]);
            wmax1[j+1]=max(wmax1[j],w[j+1]);
            wmin1[j+1]=min(wmin1[j],w[j+1]);
        }
        
        for(int j=N;j>=0;j--){
            if(j==N){
                hmax2[j]=h[j];
                hmin2[j]=h[j];
                wmax2[j]=w[j];
                wmin2[j]=w[j];
            }else{
                hmax2[j]=max(hmax2[j+1],h[j]);
                hmin2[j]=min(hmin2[j+1],h[j]);
                wmax2[j]=max(wmax2[j+1],w[j]);
                wmin2[j]=min(wmin2[j+1],w[j]);
            }
        }
        
        ll ans=(hmax1[N]-hmin1[N]+1)*(wmax1[N]-wmin1[N]+1);
        
        for(int j=1;j<N;j++){
            
            ll a=max({hmax1[j],h[j]+1,hmax2[j+1]+1}),b=min(min(hmin1[j],h[j]+1),hmin2[j+1]+1);
            ans=min(ans,(a-b+1)*(wmax1[N]-wmin1[N]+1));
            
            a=max(max(hmax1[j],h[j]-1),hmax2[j+1]-1);b=min({hmin1[j],h[j]-1,hmin2[j+1]-1});
            ans=min(ans,(a-b+1)*(wmax1[N]-wmin1[N]+1));
            
            ll c=max({wmax1[j],w[j]+1,wmax2[j+1]+1}),d=min(min(wmin1[j],w[j]+1),wmin2[j+1]+1);
            ans=min(ans,(hmax1[N]-hmin1[N]+1)*(c-d+1));
            
            c=max(max(wmax1[j],w[j]-1),wmax2[j+1]-1);d=min({wmin1[j],w[j]-1,wmin2[j+1]-1});
            ans=min(ans,(hmax1[N]-hmin1[N]+1)*(c-d+1));
            
        }
        
        cout<<ans<<endl;
        
    }
}