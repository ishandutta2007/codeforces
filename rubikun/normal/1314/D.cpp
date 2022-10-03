#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=83;
const ll INF=1LL<<60;
vector<pair<ll,int>> dis[MAX][MAX];
ll cost[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>cost[i][j];
        }
    }
    
    ll ans=INF;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(k==i||k==j) continue;
                dis[i][j].push_back({cost[i][k]+cost[k][j],k});
                //cout<<dis[i][j].back().first<<" "<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sort(all(dis[i][j]));
            //cout<<i<<" "<<j<<" "<<dis[i][j][0].first<<endl;
        }
    }
    
    K/=2;
    
    if(K==1){
        cout<<dis[0][0][0].first<<endl;
        return 0;
    }
    
    K--;
    
    vector<int> out(N),use(K);
    
    for(int bit=0;bit<ll(pow(N,K));bit++){
        int s=bit;
        for(int i=0;i<K;i++){
            use[i]=s%N;
            out[use[i]]=1;
            s/=N;
        }
        out[0]=1;
        ll sum=0;
        int from=0;
        
        for(int i=0;i<K;i++){
            ll mi=INF;
            for(pair<ll,int> a:dis[from][use[i]]){
                
                if(out[a.second]) continue;
                
                mi=a.first;
                from=use[i];
                break;
            }
            sum+=mi;
        }
        
        ll mi=INF;
        for(pair<ll,int> a:dis[from][0]){
            
            if(out[a.second]) continue;
            
            mi=a.first;
            break;
        }
        sum+=mi;
        
        ans=min(ans,sum);
        
        for(int i=0;i<K;i++){
            out[use[i]]=0;
        }
    }
    
    cout<<ans<<endl;
}