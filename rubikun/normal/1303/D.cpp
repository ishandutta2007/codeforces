#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=(1LL<<62)+(1LL<<61);

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll S,N;cin>>S>>N;
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        
        ll sum=0;
        for(int i=0;i<N;i++) sum+=A[i];
        
        if(sum<S){
            cout<<-1<<endl;
            continue;
        }else{
            ll reduce=sum-S;
            ll ans=0;
            
            for(int i=0;i<61;i++){
                if(reduce&(1LL<<i)){
                    //reduce-=(1LL<<i);
                    auto it=lower_bound(all(A),(1LL<<i));
                    ll a=*it;
                    
                    if(a!=(1LL<<i)){
                        *it=INF;
                        
                        while(a>(1LL<<i)){
                            ans++;
                            A.push_back(a/2);
                            a/=2;
                        }
                        A.push_back((1LL<<i));
                        
                        sort(all(A));
                        A.pop_back();
                    }
                }
                
                for(int j=0;j+1<A.size();j++){
                    if(reduce&(1LL<<i)){
                        if(j+2<A.size()&&A[j]==(1LL<<i)&&A[j+1]==(1LL<<i)&&A[j+2]==(1LL<<i)){
                            A[j]=INF;
                            A[j+1]=INF;
                            A.push_back((1LL<<(i+1)));
                        }
                    }else{
                        if(A[j]==(1LL<<i)&&A[j+1]==(1LL<<i)){
                            A[j]=INF;
                            A[j+1]=INF;
                            A.push_back((1LL<<(i+1)));
                        }
                    }
                }
                
                sort(all(A));
                
                while(A.size()&&A.back()==INF) A.pop_back();
            }
            
            cout<<ans<<endl;
        }
    }
}