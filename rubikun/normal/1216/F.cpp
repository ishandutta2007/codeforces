#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18;
const ll INF=1LL<<50;

int n;
ll dat[2*MAX-1];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i]=INF;
    }
}

void update(int k,ll a){
    k+=n-1;
    dat[k]=a;
    
    while(k>0){
        k=(k-1)/2;
        dat[k]=min(dat[k*2+1],dat[k*2+2]);
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
    
    int N,K;cin>>N>>K;
    string S;cin>>S;
    vector<ll> dp(N+1,INF);
    dp[0]=0;
    priority_queue<int,vector<int>,greater<int>> PQ;
    
    init(N+2);
    
    update(0,0);
    
    for(int i=1;i<=N;i++){
        if(S[i-1]=='0'){
            dp[i]=min(dp[i],dp[i-1]+i);
        }else{
            PQ.push(i);
            dp[i]=min(dp[i],dp[i-1]+i);
        }
        if(!PQ.empty()){
            int a=PQ.top();
            dp[i]=min(dp[i],query(max(0,a-K-1),i,0,0,n)+a);
            if(a+K<i+1) PQ.pop();
        }
        update(i,dp[i]);
    }
    
    cout<<dp[N]<<endl;
}