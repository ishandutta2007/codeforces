#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100003;
const ll INF=1LL<<60;
ll ans=INF;

vector<int> G[MAX];
ll score[MAX][3],rec[MAX];

void DFS(int s,int t){
    vector<int> A={0,1,2};
    
    do{
        int now=s,when=0,par=-1;
        ll sum=0;
        while(now!=t){
            sum+=score[now][A[when%3]];
            when++;
            for(auto to:G[now]){
                if(to!=par){
                    par=now;
                    now=to;
                    break;
                }
            }
        }
        sum+=score[now][A[when%3]];
        
        if(sum<ans){
            ans=min(ans,sum);
            
            now=s;when=0;par=-1;
            sum=0;
            while(now!=t){
                sum+=score[now][A[when%3]];
                rec[now]=A[when%3];
                when++;
                for(auto to:G[now]){
                    if(to!=par){
                        par=now;
                        now=to;
                        break;
                    }
                }
            }
            sum+=score[now][A[when%3]];
            rec[now]=A[when%3];
        }
        
        //cout<<sum<<endl;
        
    }while(next_permutation(all(A)));
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    for(int i=0;i<3;i++){
        for(int j=0;j<N;j++){
            cin>>score[j][i];
        }
    }
    
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    bool ok=true;
    vector<int> one;
    for(int i=0;i<N;i++){
        if(G[i].size()==1) one.push_back(i);
        else if(G[i].size()!=2) ok=false;
    }
    
    if(!ok){
        cout<<-1<<endl;
        return 0;
    }
    
    int s=one[0],t=one[1];
    
    DFS(s,t);
    
    cout<<ans<<endl;
    
    for(int i=0;i<N;i++){
        cout<<rec[i]+1<<" ";
    }
    cout<<endl;
    
}