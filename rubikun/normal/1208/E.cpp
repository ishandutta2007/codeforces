#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<20,INF=1<<30;

int n,dat[2*MAX-1];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i]=-INF;
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
    
    if(r<=a||b<=l) return -INF;
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
    
    int N,W;cin>>N>>W;
    vector<ll> S[W];
    ll sum=0;
    for(int i=0;i<N;i++){
        int L;cin>>L;
        vector<ll> A(L);
        ll maxi=-INF;
        int point=0;
        for(int j=0;j<L;j++){
            cin>>A[j];
            if(A[j]>maxi){
                maxi=A[j];
                point=j;
            }
        }
        if(maxi<=0){
            if(L*2<=W) continue;
            init(L+1);
            for(int j=0;j<L;j++){
                update(j,int(A[j]));
            }
            for(int j=W-L;j<L;j++){
                int a=query(j-(W-L),j+1,0,0,n);
                S[j].push_back(ll(a));
            }
            continue;
        }
        sum+=maxi;
        init(L+1);
        
        for(int j=0;j<L;j++){
            update(j,int(A[j]));
        }
        for(int j=0;j<point;j++){
            int a=query(max(0,j-(W-L)),j+1,0,0,n);
            if(j<W-L) a=max(a,0);
            S[j].push_back(ll(-maxi+a));
        }
        
        for(int j=point+1;j<L;j++){
            int a=query(j,min(j+(W-L),L-1)+1,0,0,n);
            if(j+(W-L)>=L) a=max(a,0);
            S[j+(W-L)].push_back(ll(-maxi+a));
        }
    }
    
    for(int i=0;i<W;i++){
        ll cnt=0;
        for(int j=0;j<S[i].size();j++){
            cnt+=S[i][j];
        }
        if(i) cout<<" ";
        cout<<sum+cnt;
    }
    
    cout<<endl;
    
}