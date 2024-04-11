#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1505,INF=1<<30;

int par[MAX],size[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        size[i]=1;
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)){
        size[root(a)]+=size[root(b)];
        par[root(b)]=root(a);
    }
}

bool check(int a,int b){
    return root(a)==root(b);
}

int main(){
    
    /*std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);*/
    
    int N,K;cin>>N>>K;
    if(K==1){
        init(N);
        
        for(int i=1;i<=N;i++){
            for(int j=i+1;j<=N;j++){
                cout<<"? "<<i<<endl;
                char a;cin>>a;
                cout<<"? "<<j<<endl;
                char b;cin>>b;
                if(b=='Y') unite(i-1,j-1);
            }
        }
        
        set<int> SE;
        
        for(int i=0;i<N;i++){
            SE.insert(root(i));
        }
        
        cout<<"! "<<SE.size()<<endl;
    }
    vector<int> ans(N+1,1);
    
    for(int i=0;i<N/K;i++){
        for(int j=0;j<K;j++){
            cout<<"? "<<(i*K+j+1)<<endl;
            char a;cin>>a;
            if(a=='Y') ans[i*K+j+1]=0;
        }
        cout<<"R"<<endl;
    }
    
    int turn=N/K;
    
    while(turn>=2){
        
        for(int x=0;x+1<turn;x+=2){
            for(int y=0;y<N/turn;y+=K){
                for(int t=0;t<(N/turn)/max(1,K/2);t++){
                    for(int j=1;j<=max(1,K/2);j++){
                        if(ans[x*N/turn+t*K/2+j]){
                            cout<<"? "<<(x*N/turn+t*K/2+j)<<endl;
                            char a;cin>>a;
                            if(a=='Y'&&(x*N/turn+t*K/2+j)!=1) ans[x*N/turn+t*K/2+j]=0;
                        }else{
                            cout<<"? "<<1<<endl;
                            char a;cin>>a;
                            //if(a=='Y') ans[x*N/turn+t*K/2+j]=0;
                        }
                    }
                    
                    for(int j=1;j<=max(1,K/2);j++){
                        int yy=(x+1)*N/turn+t*K/2+j+y;
                        if(yy>(x+2)*N/turn) yy-=N/turn;
                        if(ans[yy]){
                            cout<<"? "<<yy<<endl;
                            char a;cin>>a;
                            if(a=='Y') ans[yy]=0;
                        }else{
                            cout<<"? "<<1<<endl;
                            char a;cin>>a;
                        }
                    }
                    
                }
                
                if(K>=2){
                    for(int j=1;j<=max(1,K/2);j++){
                        if(ans[x*N/turn+0*K/2+j]){
                            cout<<"? "<<(x*N/turn+0*K/2+j)<<endl;
                            char a;cin>>a;
                            if(a=='Y'&&(x*N/turn+0*K/2+j)!=1) ans[x*N/turn+0*K/2+j]=0;
                        }else{
                            cout<<"? "<<1<<endl;
                            char a;cin>>a;
                            //if(a=='Y') ans[x*N/turn+t*K/2+j]=0;
                        }
                    }
                }
                
                cout<<"R"<<endl;
            }
        }
        
        turn/=2;
    }
    
    int res=0;
    
    for(int i=1;i<=N;i++) res+=ans[i];
    
    cout<<"! "<<res<<endl;
}