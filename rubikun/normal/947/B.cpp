#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=1<<18;
const ll INF=1LL<<60;

int n;
ll max_fi[2*MAX-1],max_se[2*MAX-1],max_cnt[2*MAX-1];
ll min_fi[2*MAX-1],min_se[2*MAX-1],min_cnt[2*MAX-1];
ll sum[2*MAX-1];
ll lazyadd[2*MAX-1],lazyupdate[2*MAX-1];
bool done[2*MAX-1];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
}

void update_node_max(ll x,int k){
    sum[k]+=(x-max_fi[k])*max_cnt[k];
    
    if(max_fi[k]==min_fi[k]){
        max_fi[k]=min_fi[k]=x;
    }else if(max_fi[k]==min_se[k]){
        max_fi[k]=min_se[k]=x;
    }else{
        max_fi[k]=x;
    }
    
    if(done[k]){
        lazyupdate[k]=min(lazyupdate[k],x);
    }
}

void update_node_min(ll x,int k){
    sum[k]+=(x-min_fi[k])*min_cnt[k];
    
    if(min_fi[k]==max_fi[k]){
        min_fi[k]=max_fi[k]=x;
    }else if(min_fi[k]==max_se[k]){
        min_fi[k]=max_se[k]=x;
    }else{
        min_fi[k]=x;
    }
    
    if(done[k]){
        lazyupdate[k]=max(lazyupdate[k],x);
    }
}

void update_node_(ll x,int k,int l,int r){
    max_fi[k]=x;
    max_se[k]=-INF;
    max_cnt[k]=r-l;
    
    min_fi[k]=x;
    min_se[k]=INF;
    min_cnt[k]=r-l;
    
    sum[k]=x*(r-l);
    
    lazyupdate[k]=x;
    done[k]=1;
    lazyadd[k]=0;
}

void update_node_add(ll x,int k,int l,int r){
    max_fi[k]+=x;
    if(max_se[k]!=-INF) max_se[k]+=x;
    
    min_fi[k]+=x;
    if(min_se[k]!=INF) min_se[k]+=x;
    
    sum[k]+=x*(r-l);
    
    if(done[k]){
        lazyupdate[k]+=x;
    }else{
        lazyadd[k]+=x;
    }
}

void eval(int k,int l,int r){
    
    if(l+1>=r) return;
    
    if(done[k]){
        update_node_(lazyupdate[k],2*k+1,l,(l+r)/2);
        update_node_(lazyupdate[k],2*k+2,(l+r)/2,r);
        done[k]=0;
        return;
    }
    
    if(lazyadd[k]){
        update_node_add(lazyadd[k],2*k+1,l,(l+r)/2);
        update_node_add(lazyadd[k],2*k+2,(l+r)/2,r);
        lazyadd[k]=0;
    }
    
    if(max_fi[k]<max_fi[2*k+1]){
        update_node_max(max_fi[k],2*k+1);
    }
    if(min_fi[k]>min_fi[2*k+1]){
        update_node_min(min_fi[k],2*k+1);
    }
    if(max_fi[k]<max_fi[2*k+2]){
        update_node_max(max_fi[k],2*k+2);
    }
    if(min_fi[k]>min_fi[2*k+2]){
        update_node_min(min_fi[k],2*k+2);
    }
}

void merge(int k){
    sum[k]=sum[2*k+1]+sum[2*k+2];
    
    if(max_fi[2*k+1]>max_fi[2*k+2]){
        max_fi[k]=max_fi[2*k+1];
        max_cnt[k]=max_cnt[2*k+1];
        max_se[k]=max(max_se[2*k+1],max_fi[2*k+2]);
    }else if(max_fi[2*k+1]<max_fi[2*k+2]){
        max_fi[k]=max_fi[2*k+2];
        max_cnt[k]=max_cnt[2*k+2];
        max_se[k]=max(max_fi[2*k+1],max_se[2*k+2]);
    }else{
        max_fi[k]=max_fi[2*k+1];
        max_cnt[k]=max_cnt[2*k+1]+max_cnt[2*k+2];
        max_se[k]=max(max_se[2*k+1],max_se[2*k+2]);
    }
    
    if(min_fi[2*k+1]<min_fi[2*k+2]){
        min_fi[k]=min_fi[2*k+1];
        min_cnt[k]=min_cnt[2*k+1];
        min_se[k]=min(min_se[2*k+1],min_fi[2*k+2]);
    }else if(min_fi[2*k+1]>min_fi[2*k+2]){
        min_fi[k]=min_fi[2*k+2];
        min_cnt[k]=min_cnt[2*k+2];
        min_se[k]=min(min_fi[2*k+1],min_se[2*k+2]);
    }else{
        min_fi[k]=min_fi[2*k+1];
        min_cnt[k]=min_cnt[2*k+1]+min_cnt[2*k+2];
        min_se[k]=min(min_se[2*k+1],min_se[2*k+2]);
    }
}

void update_chmax(int a,int b,ll x,int k,int l,int r){
    
    eval(k,l,r);
    
    if(r<=a||b<=l||min_fi[k]>=x) return;
    
    if(a<=l&&r<=b&&min_se[k]>x){
        update_node_min(x,k);
        eval(k,l,r);
    }else{
        update_chmax(a,b,x,2*k+1,l,(l+r)/2);
        update_chmax(a,b,x,2*k+2,(l+r)/2,r);
        
        merge(k);
    }
}

void update_chmin(int a,int b,ll x,int k,int l,int r){
    
    eval(k,l,r);
    
    if(r<=a||b<=l||max_fi[k]<=x) return;
    
    if(a<=l&&r<=b&&max_se[k]<x){
        update_node_max(x,k);
        eval(k,l,r);
    }else{
        update_chmin(a,b,x,2*k+1,l,(l+r)/2);
        update_chmin(a,b,x,2*k+2,(l+r)/2,r);
        
        merge(k);
    }
}

void update(int a,int b,ll x,int k,int l,int r){
    eval(k,l,r);
    
    if(r<=a||b<=l) return;
    
    if(a<=l&&r<=b){
        update_node_(x,k,l,r);
        eval(k,l,r);
    }else{
        update(a,b,x,2*k+1,l,(l+r)/2);
        update(a,b,x,2*k+2,(l+r)/2,r);
        
        merge(k);
    }
}

void add(int a,int b,ll x,int k,int l,int r){
    eval(k,l,r);
    
    if(r<=a||b<=l) return;
    
    if(a<=l&&r<=b){
        update_node_add(x,k,l,r);
        eval(k,l,r);
    }else{
        add(a,b,x,2*k+1,l,(l+r)/2);
        add(a,b,x,2*k+2,(l+r)/2,r);
        
        merge(k);
    }
}

ll query_sum(int a,int b,int k,int l,int r){
    
    if(r<=a||b<=l) return 0;
    
    eval(k,l,r);
    
    if(a<=l&&r<=b) return sum[k];
    
    ll vl=query_sum(a,b,2*k+1,l,(l+r)/2);
    ll vr=query_sum(a,b,2*k+2,(l+r)/2,r);
    return vl+vr;
}

ll query_max(int a,int b,int k,int l,int r){
    
    if(r<=a||b<=l) return -INF;
    
    eval(k,l,r);
    
    if(a<=l&&r<=b) return max_fi[k];
    
    ll vl=query_max(a,b,2*k+1,l,(l+r)/2);
    ll vr=query_max(a,b,2*k+2,(l+r)/2,r);
    return max(vl,vr);
}

ll query_min(int a,int b,int k,int l,int r){
    
    if(r<=a||b<=l) return INF;
    
    eval(k,l,r);
    
    if(a<=l&&r<=b) return min_fi[k];
    
    ll vl=query_min(a,b,2*k+1,l,(l+r)/2);
    ll vr=query_min(a,b,2*k+2,(l+r)/2,r);
    return min(vl,vr);
}
//chmin,chmax,add,sumverify

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    init(N);
    update(0,N,0,0,0,N);
    
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    
    for(int q=0;q<N;q++){
        ll a=query_sum(0,N,0,0,N)+A[q];
        add(q,q+1,A[q],0,0,N);
        add(0,q+1,-B[q],0,0,N);
        update_chmax(0,q+1,0,0,0,N);
        ll b=query_sum(0,N,0,0,N);
        cout<<a-b<<" ";
    }
    cout<<endl;
}