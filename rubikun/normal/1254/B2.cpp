#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;
const ll INF=1LL<<61;
 
int main(){
    
    int N;cin>>N;
    ll cnt=0;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        //cin>>A[i];
        scanf("%d",&A[i]);
        cnt+=ll(A[i]);
    }
    
    if(cnt<=1){
        cout<<-1<<endl;
        return 0;
    }
    
    vector<ll> prime;
    for(ll k=2;k*k<=cnt;k++){
        if(cnt%k==0){
            prime.push_back(k);
            while(cnt%k==0) cnt/=k;
        }
    }
    
    if(cnt!=1) prime.push_back(cnt);
    
    ll ans=INF;
    for(ll k:prime){
        //if(cnt%k!=0) continue;
        
        ll sum=0,goukei=0;
        
        vector<pair<int,ll>> when;
        
        if(k!=1){
            for(int i=0;i<N;i++){
                if(goukei>=ans) break;
                if(A[i]&&sum+ll(A[i])<k){
                    sum+=ll(A[i]);
                    when.push_back({i,ll(A[i])});
                }else if(sum+ll(A[i])>=k){
                    ll aaa=0,bbb=0;
                    when.push_back({i,k-sum});
                    ll b=ll(A[i])-(k-sum);
                    //A[i]-=(k-sum);
                    ll half=0;
                    int point=-1;
                    for(int j=0;j<when.size();j++){
                        half+=when[j].second;
                        if(half>=k/2){
                            point=when[j].first;
                            break;
                        }
                    }
                    
                    for(int j=0;j<when.size();j++){
                        aaa+=ll(abs(when[j].first-point))*when[j].second;
                    }
                    
                    half=0;
                    point=-1;
                    for(int j=0;j<when.size();j++){
                        half+=when[j].second;
                        if(half>=k/2+1){
                            point=when[j].first;
                            break;
                        }
                    }
                    
                    for(int j=0;j<when.size();j++){
                        bbb+=ll(abs(when[j].first-point))*when[j].second;
                    }
                    
                    when.clear();
                    
                    b%=k;
                    if(b) when.push_back({i,b});
                    sum=b;
                    
                    goukei+=min(aaa,bbb);
                    
                    //cout<<k<<" "<<i<<" "<<aaa<<" "<<bbb<<" "<<when.size()<<endl;
                }
                //if(k==3) cout<<goukei<<endl;
            }
            
            ans=min(ans,goukei);
        }
    }
    
    cout<<ans<<"\n";
}