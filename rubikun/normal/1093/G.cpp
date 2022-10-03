#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1000000000;

int n;
int dat[2*MAX-1][64];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<64;j++){
            if(j<32) dat[i][j]=-INF;
            else dat[i][j]=INF;
        }
    }
}

void update(int k,vector<int> &a){
    k+=n-1;
    for(int j=0;j<32;j++){
        int sum=0;
        for(int x=0;x<5;x++){
            if(j&(1<<x)) sum+=a[x];
            else sum-=a[x];
        }
        dat[k][j]=sum;
        dat[k][j+32]=sum;
    }
    
    while(k>0){
        k=(k-1)/2;
        for(int j=0;j<64;j++){
            if(j<32){
                dat[k][j]=max(dat[k*2+1][j],dat[k*2+2][j]);
            }else{
                dat[k][j]=min(dat[k*2+1][j],dat[k*2+2][j]);
            }
        }
    }
}

int query(int a,int b,int k,int l,int r,int kind){
    
    if(kind<32){
        if(r<=a||b<=l) return -INF;
        if(a<=l&&r<=b) return dat[k][kind];
        else{
            int vl=query(a,b,2*k+1,l,(l+r)/2,kind);
            int vr=query(a,b,2*k+2,(l+r)/2,r,kind);
            return max(vl,vr);
        }
    }else{
        if(r<=a||b<=l) return INF;
        if(a<=l&&r<=b) return dat[k][kind];
        else{
            int vl=query(a,b,2*k+1,l,(l+r)/2,kind);
            int vr=query(a,b,2*k+2,(l+r)/2,r,kind);
            return min(vl,vr);
        }
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    init(N);
    
    for(int i=0;i<N;i++){
        vector<int> A(5,0);
        for(int k=0;k<K;k++){
            scanf("%d",&A[k]);
        }
        update(i,A);
    }
    
    int Q;cin>>Q;
    
    for(int q=0;q<Q;q++){
        int x;scanf("%d",&x);
        if(x==1){
            int y;scanf("%d",&y);y--;
            vector<int> A(5,0);
            for(int k=0;k<K;k++){
                scanf("%d",&A[k]);
            }
            update(y,A);
        }else{
            int l,r;scanf("%d %d",&l,&r);
            l--;r--;
            int ans=-2*INF;
            for(int j=0;j<32;j++){
                int a=query(l,r+1,0,0,n,j);
                int b=query(l,r+1,0,0,n,32+j);
                ans=max(ans,a-b);
            }
            printf("%d\n",ans);
        }
    }
    
}