#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2000005,INF=1<<30;
vector<int> prime;//i
bool is_prime[MAX+1];

void sieve(int n){
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
    }
    
    is_prime[0]=is_prime[1]=false;
    
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
            }
        }
    }
}

int id[MAX],ok[MAX];
vector<int> G[100005];

int ans=INF;
int dis[100005];
bool used[180][100005];

void BFS(int u){
    vector<pair<int,int>> SE;
    dis[u]=0;
    queue<int> Q;
    Q.push(u);
    
    while(!Q.empty()){
        int a=Q.front();Q.pop();
        for(int to:G[a]){
            int b=min(a,to),c=max(a,to);
            if(dis[to]==INF){
                dis[to]=dis[a]+1;
                Q.push(to);
                SE.push_back({b,c});
                used[b][c]=1;
            }else if(used[b][c]==0){
                ans=min(ans,dis[to]+dis[a]+1);
            }
        }
    }
    
    for(int i=0;i<SE.size();i++) used[SE[i].first][SE[i].second]=0;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(MAX-2);
    
    map<pair<int,int>,bool> MA2;
    
    for(int i=0;i<prime.size();i++){
        if(prime[i]>=1000000) break;
        id[prime[i]]=i+1;
    }
    for(int i=1;i<=1000;i++) ok[i*i]=1;
    int N;cin>>N;
    
    int anss=INF;
    for(int i=0;i<N;i++){
        int a;cin>>a;
        if(ok[a]){
            cout<<1<<endl;
            return 0;
        }
        int u=-1,v=-1;
        for(int p:prime){
            if(p>1000) break;
            int cnt=0;
            while(a%p==0){
                a/=p;
                cnt++;
            }
            if(cnt%2){
                if(u==-1) u=p;
                else v=p;
            }
        }
        if(a!=1){
            if(u==-1) u=a;
            else v=a;
        }
        
        if(u==-1){
            cout<<1<<endl;
            return 0;
        }
        if(v==-1){
            G[0].push_back(id[u]);
            G[id[u]].push_back(0);
            
            //cout<<0<<" "<<id[u]<<endl;
            
            if(MA2[{0,id[u]}]){
                anss=2;
            }
            MA2[{0,id[u]}]=1;
        }else{
            G[id[u]].push_back(id[v]);
            G[id[v]].push_back(id[u]);
            
            //cout<<id[u]<<" "<<id[v]<<endl;
            
            if(MA2[{id[u],id[v]}]){
                anss=2;
            }
            MA2[{id[u],id[v]}]=1;
        }
    }
    
    if(anss==2){
        cout<<2<<endl;
        return 0;
    }
    
    for(int k=0;k<=170;k++){
        for(int i=0;i<=100000;i++){
            dis[i]=INF;
        }
        BFS(k);
        //cout<<ans<<endl;
    }
    
    if(ans==INF) ans=-1;
    cout<<ans<<endl;
    
}