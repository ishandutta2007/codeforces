#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;
int n,dat[2*MAX-1];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i]=-1;
    }
}

void update(int k,int a){
    k+=n-1;
    dat[k]=a;
    
    while(k>0){
        k=(k-1)/2;
        dat[k]=max(dat[k*2+1],dat[k*2+2]);
    }
}

int query(int a,int b,int k,int l,int r){
    
    if(r<=a||b<=l) return -1;
    if(a<=l&&r<=b) return dat[k];
    else{
        int vl=query(a,b,2*k+1,l,(l+r)/2);
        int vr=query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
}


int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    int M;cin>>M;
    
    init(M);
    
    vector<pair<int,int>> Q(M);
    vector<int> seen(N,-1);
    
    for(int i=0;i<M;i++){
        int a;cin>>a;
        if(a==1){
            int b,c;cin>>b>>c;
            b--;
            Q[i]=make_pair(b,c);
            seen[b]=i;
        }else{
            int b;cin>>b;
            update(i,b);
            Q[i]=make_pair(-1,b);
        }
    }
    
    for(int i=0;i<N;i++){
        if(seen[i]==-1){
            A[i]=max(A[i],query(0,M,0,0,n));
        }else{
            A[i]=max(Q[seen[i]].second,query(seen[i]+1,M,0,0,n));
        }
    }
    
    for(int i=0;i<N;i++){
        if(i) cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    
    
    
    
}