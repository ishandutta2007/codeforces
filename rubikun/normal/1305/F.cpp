#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1005,INF=1000000000;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    mt19937_64 rng(58);
    
    int N;cin>>N;
    vector<ll> A(N),seen(2000000);
    map<ll,ll> MA;
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int t=0;t<10000;t++){
        int a=rng()%N,b=rng()%N;
        if(a==b) continue;
        
        ll c=A[a],d=A[b];
        
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                ll g=gcd(c+i,d+j);
                if(g>=5) MA[g]++;
            }
        }
    }
    
    ll ans=INF,cnt=0;
    
    for(int i=0;i<N;i++){
        if(A[i]%2) cnt++;
    }
    ans=min(ans,cnt);
    
    cnt=0;
    
    for(int i=0;i<N;i++){
        if(A[i]==1) cnt+=2;
        else if(A[i]%3) cnt++;
    }
    ans=min(ans,cnt);
    
    vector<pair<ll,ll>> B;
    
    for(auto it=MA.begin();it!=MA.end();it++){
        B.push_back({(*it).second,(*it).first});
    }
    
    sort(all(B));
    reverse(all(B));
    
    for(int x=0;x<B.size();x++){
        if(B[x].first<=30) break;
        
        for(ll k=2;k*k<=B[x].second;k++){
            if(B[x].second%k==0){
                if(seen[k]==0){
                    seen[k]=1;
                    
                    ll cnt=0;
                    
                    for(int i=0;i<N;i++){
                        if(A[i]<k) cnt+=(k-A[i]);
                        else cnt+=min(A[i]%k,k-A[i]%k);
                        
                        if(cnt>=ans) break;
                    }
                    
                    ans=min(ans,cnt);
                    
                }
                while(B[x].second%k==0){
                    B[x].second/=k;
                }
            }
        }
        
        if(B[x].second>=2){
            ll cnt=0;
            
            for(int i=0;i<N;i++){
                if(A[i]<B[x].second) cnt+=(B[x].second-A[i]);
                else cnt+=min(A[i]%B[x].second,B[x].second-A[i]%B[x].second);
                
                if(cnt>=ans) break;
            }
            
            ans=min(ans,cnt);
        }
    }
    
    cout<<ans<<endl;
}