#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=1<<19,INF=1<<30;

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
    
    int Q;cin>>Q;
    for(int q=0;q<Q;q++){
        int N;cin>>N;
        init(N);
        vector<int> A(N),B(N);
        
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        
        for(int i=0;i<N;i++){
            cin>>B[i];
        }
        
        list<int> when[N+1];
        for(int i=0;i<N;i++){
            when[A[i]].push_back(i);
            update(i,A[i]);
        }
        bool ok=true;
        for(int i=0;i<N;i++){
            if(when[B[i]].size()==0){
                ok=false;
                break;
            }
            int a=*(when[B[i]].begin());
            int b=query(0,a+1,0,0,n);
            if(B[i]>b){
                ok=false;
                break;
            }
            when[B[i]].pop_front();
            update(a,INF);
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}