#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()

const int mod=1000000007,MAX=1<<12,INF=1<<30;
int n,dat[2*MAX-1];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i]=INF;
    }
}

void update(int k,int a){
    k+=n-1;
    dat[k]=a;
    
    while(k>0){
        k=(k-1)/2;
        dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
}

int query(int a,int b,int k,int l,int r){
    
    if(r<=a||b<=l) return INF;
    if(a<=l&&r<=b) return dat[k];
    else{
        int vl=query(a,b,2*k+1,l,(l+r)/2);
        int vr=query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M,A,B;cin>>N>>M>>A>>B;
    ll g,x,y,z;cin>>g>>x>>y>>z;
    vector<vector<int>> S(N,vector<int>(M,0)),ud(N,vector<int>(M,0)),lr(N,vector<int>(M,0));
    S[0][0]=int(g);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(i==0&&j==0) continue;
            if(j==0) S[i][j]=int((S[i-1][M-1]*x+y)%z);
            else S[i][j]=int((S[i][j-1]*x+y)%z);
        }
    }
    
    for(int j=0;j<M;j++){
        init(N);
        for(int i=0;i<N;i++){
            update(i,S[i][j]);
        }
        for(int i=0;i<N-A+1;i++){
            if(i&&S[i-1][j]>ud[i-1][j]) ud[i][j]=min(S[i+A-1][j],ud[i-1][j]);
            else ud[i][j]=query(i,i+A,0,0,n);
        }
    }
    
    ll ans=0;
    
    for(int i=0;i<N-A+1;i++){
        init(M);
        for(int j=0;j<M;j++){
            update(j,ud[i][j]);
        }
        for(int j=0;j<M-B+1;j++){
            if(j&&ud[i][j-1]>lr[i][j-1]) lr[i][j]=min(ud[i][j+B-1],lr[i][j-1]);
            else lr[i][j]=query(j,j+B,0,0,n);
            
            ans+=lr[i][j];
        }
    }
    
    cout<<ans<<endl;
    
    
    
}