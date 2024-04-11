#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=(1<<30)-1;

int n,dat[2*MAX-1][9],dat2[2*MAX-1][9];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<9;j++){
            dat[i][j]=INF;
            dat2[i][j]=INF;
        }
    }
}

void init2(){
    for(int k=n-2;k>=0;k--){
        for(int dig=0;dig<9;dig++){
            if(dat[2*k+1][dig]<dat[2*k+2][dig]){
                dat[k][dig]=dat[2*k+1][dig];
                dat2[k][dig]=min(dat2[2*k+1][dig],dat[2*k+2][dig]);
            }else{
                dat[k][dig]=dat[2*k+2][dig];
                dat2[k][dig]=min(dat2[2*k+2][dig],dat[2*k+1][dig]);
            }
        }
    }
}

void update(int k,int a,int dig){
    k+=n-1;
    dat[k][dig]=a;
    
    while(k>0){
        k=(k-1)/2;
        if(dat[2*k+1][dig]<dat[2*k+2][dig]){
            dat[k][dig]=dat[2*k+1][dig];
            dat2[k][dig]=min(dat2[2*k+1][dig],dat[2*k+2][dig]);
        }else{
            dat[k][dig]=dat[2*k+2][dig];
            dat2[k][dig]=min(dat2[2*k+2][dig],dat[2*k+1][dig]);
        }
    }
}

pair<int,int> query(int a,int b,int k,int l,int r,int dig){
    
    if(r<=a||b<=l) return {INF,INF};
    if(a<=l&&r<=b) return {dat[k][dig],dat2[k][dig]};
    else{
        pair<int,int> vl=query(a,b,2*k+1,l,(l+r)/2,dig);
        pair<int,int> vr=query(a,b,2*k+2,(l+r)/2,r,dig);
        
        if(vl.first<vr.first){
            return {vl.first,min(vl.second,vr.first)};
        }else{
            return {vr.first,min(vr.second,vl.first)};
        }
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    init(N+2);
    
    for(int i=0;i<N;i++){
        int a;
        scanf("%d",&a);
        int b=a;
        for(int j=0;j<9;j++){
            if(b%10) dat[n-1+i][j]=a;
            b/=10;
        }
    }
    
    init2();
    
    for(int i=0;i<M;i++){
        int q,a,b;
        scanf("%d %d %d",&q,&a,&b);
        a--;
        if(q==1){
            int c=b;
            for(int j=0;j<9;j++){
                if(c%10) update(a,b,j);
                else update(a,INF,j);
                c/=10;
            }
        }else{
            bool ok=false;
            int ans=INF*2;
            for(int j=0;j<9;j++){
                pair<int,int> P=query(a,b,0,0,n,j);
                if(P.second!=INF){
                    ok=true;
                    ans=min(ans,P.first+P.second);
                }
            }
            if(ok) printf("%d\n",ans);
            else{
                ans=-1;
                printf("%d\n",ans);
            }
        }
    }
}