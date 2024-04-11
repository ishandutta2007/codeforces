#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<19,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    map<pair<int,int>,bool> MA;
    vector<pair<int,int>> G(M);
    for(int i=0;i<M;i++){
        int a,b;
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        a--;b--;
        MA[{a,b}]=1;
        MA[{b,a}]=1;
        G[i]={a,b};
    }
    
    //
    vector<int> p;
    for(int i=1;i*i<=N;i++){
        if(N%i==0){
            p.push_back(i);
            if(N/i!=N) p.push_back(N/i);
        }
    }
    
    bool ans=false;
    
    for(int d:p){
        bool ok=true;
        for(int i=0;i<M;i++){
            int a=G[i].first+d,b=G[i].second+d;
            if(a>=N) a-=N;
            if(b>=N) b-=N;
            
            if(MA[{a,b}]==0&&MA[{b,a}]==0){
                ok=false;
                break;
            }
        }
        
        if(ok) ans=true;
    }
    
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
}