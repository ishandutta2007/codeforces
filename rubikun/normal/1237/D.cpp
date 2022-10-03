#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17;
const ll INF=1LL<<40;
int n;
ll dat[2*MAX-1];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i]=0;
    }
}

void add(int k,ll a){
    k+=(n-1);
    dat[k]+=a;
    while(k){
        k=(k-1)/2;
        dat[k]=min(dat[2*k+1],dat[2*k+2]);
    }
}

ll query(int a,int b,int k,int l,int r){
    
    if(r<=a||b<=l) return INF;
    if(a<=l&&r<=b) return dat[k];
    else{
        ll vl=query(a,b,2*k+1,l,(l+r)/2);
        ll vr=query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<ll> A(N),to(N,INF);
    for(int i=0;i<N;i++){
        scanf("%lld",&A[i]);
        //cin>>A[i];
    }
    
    priority_queue<pair<ll,int>> PQ;
    
    for(int i=0;i<N;i++){
        if(!PQ.empty()){
            while(!PQ.empty()&&PQ.top().first>A[i]*2){
                to[PQ.top().second]=i-PQ.top().second;
                PQ.pop();
            }
        }
        PQ.push(make_pair(A[i],i));
    }
    for(int i=0;i<N;i++){
        if(!PQ.empty()){
            while(!PQ.empty()&&PQ.top().first>A[i]*2){
                if(to[PQ.top().second]==INF) to[PQ.top().second]=N+i-PQ.top().second;
                PQ.pop();
            }
        }
        PQ.push(make_pair(A[i],i));
    }
    init(N);
    
    for(int i=0;i<N;i++){
        add(i,to[i]+i);
    }
    
    for(int i=0;i<N;i++){
        if(i) printf(" ");
        ll a=query(0,N,0,0,n);
        if(a>=INF-2*N){
            printf("-1");
            //cout<<-1;
        }
        else{
            printf("%lld",a-i);
            //cout<<a-i;
        }
        add(i,N);
    }
    
    cout<<endl;
    
}