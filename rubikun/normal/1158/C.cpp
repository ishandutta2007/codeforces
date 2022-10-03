#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<19;
const ll INF=1LL<<50;

int n;
ll dat[2*MAX-1];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i]=0;
    }
}

void update(int k,ll a){
    k+=n-1;
    dat[k]=a;
    
    while(k>0){
        k=(k-1)/2;
        dat[k]=max(dat[k*2+1],dat[k*2+2]);
    }
}

ll query(int a,int b,int k,int l,int r){
    
    if(r<=a||b<=l) return 0;
    if(a<=l&&r<=b) return dat[k];
    else{
        ll vl=query(a,b,2*k+1,l,(l+r)/2);
        ll vr=query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
}

vector<int> G[MAX];
int ans[MAX];
int M;

void DFS(int u,int p,int &time){
    ans[u]=time;
    for(int to:G[u]){
        if(to==p) continue;
        time--;
        DFS(to,u,time);
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        int N;
        //cin>>N;
        scanf("%d",&N);
        init(N);
        vector<int> A(N);
        for(int i=0;i<N;i++){
            //cin>>A[i];
            scanf("%d",&A[i]);
            if(A[i]==-1) A[i]=i+2;
            update(i,A[i]);
        }
        bool ok=true;
        
        for(int i=0;i<N;i++){
            if(query(i,A[i]-1,0,0,n)>A[i]) ok=false;
        }
        
        if(!ok) printf("-1\n");
        else{
            for(int i=0;i<=N;i++) G[i].clear();
            for(int i=0;i<N;i++) G[A[i]-1].push_back(i);
            for(int i=0;i<=N;i++) sort(G[i].begin(),G[i].end());
            M=N+1;
            DFS(N,-1,M);
            for(int i=0;i<N;i++) printf("%d ",ans[i]);
            printf("\n");
        }
        
        T--;
    }
}