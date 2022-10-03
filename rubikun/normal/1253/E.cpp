#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;

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

bool compare(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.first<b.first;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    init(M+5);
    vector<pair<int,int>> P(N);
    
    int ans=INF;
    
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        int c=max(1,a-b),d=min(M,a+b);
        //P[i].first=M+1-d;
        //P[i].second=M+1-c;
        P[i].first=c;
        P[i].second=d;
    }
    
    sort(all(P),compare);
    //reverse(all(P));
    
    vector<int> dp(M+1,INF);
    if(P[0].first==1){
        for(int i=1;i<=P[0].second;i++) dp[i]=0;
        for(int i=P[0].second;i<=M;i++) dp[i]=i-P[0].second;
    }else{
        for(int i=1;i<=min(M,P[0].second+P[0].first-1);i++) dp[i]=P[0].first-1;
        for(int i=min(M,P[0].second+P[0].first-1)+1;i<=M;i++) dp[i]=dp[i-1]+1;
    }
    update(0,0);
    for(int i=1;i<=M;i++) update(i,dp[i]);
    
    for(int i=1;i<N;i++){
        /*for(int j=1;j<P[i].first;j++){
            dp[j]=min(dp[j],query(j-1,j,0,0,n)+P[i].first-j);
        }
        for(int j=P[i].first;j<P[i].second;j++){
            dp[j]=min(dp[j],query(P[i].first-1,P[i].second+1,0,0,n));
        }*/
        for(int j=P[i].second;j<=M;j++){
            dp[j]=min(dp[j],query(max(0,P[i].first-(j-P[i].second)-1),n+1,0,0,n)+(j-P[i].second));
            //if(P[i].first-(j-P[i].second)==1) dp[1]=min(dp[1],j-P[i].second);
        }
        for(int j=P[i].second;j<=M;j++){
            if(query(j,j+1,0,0,n)>dp[j]) update(j,dp[j]);
        }
    }
    
    //for(int i=1;i<=M;i++) cout<<i<<" "<<dp[i]<<endl;
    
    ans=min(ans,dp[M]);
    
    init(M+5);
    
    for(int j=0;j<=M;j++) dp[j]=INF;
    
    for(int i=0;i<N;i++){
        int c=P[i].first,d=P[i].second;
        P[i].first=M+1-d;
        P[i].second=M+1-c;
        //P[i].first=c;
        //P[i].second=d;
    }
    
    sort(all(P),compare);
    //reverse(all(P));
    if(P[0].first==1){
        for(int i=1;i<=P[0].second;i++) dp[i]=0;
        for(int i=P[0].second;i<=M;i++) dp[i]=i-P[0].second;
    }else{
        for(int i=1;i<=min(M,P[0].second+P[0].first-1);i++) dp[i]=P[0].first-1;
        for(int i=min(M,P[0].second+P[0].first-1)+1;i<=M;i++) dp[i]=dp[i-1]+1;
    }
    update(0,0);
    for(int i=1;i<=M;i++) update(i,dp[i]);
    
    for(int i=1;i<N;i++){
        /*for(int j=1;j<P[i].first;j++){
         dp[j]=min(dp[j],query(j-1,j,0,0,n)+P[i].first-j);
         }
         for(int j=P[i].first;j<P[i].second;j++){
         dp[j]=min(dp[j],query(P[i].first-1,P[i].second+1,0,0,n));
         }*/
        for(int j=P[i].second;j<=M;j++){
            dp[j]=min(dp[j],query(max(0,P[i].first-(j-P[i].second)-1),n+1,0,0,n)+(j-P[i].second));
            //if(P[i].first-(j-P[i].second)==1) dp[1]=min(dp[1],j-P[i].second);
        }
        for(int j=P[i].second;j<=M;j++){
            if(query(j,j+1,0,0,n)>dp[j]) update(j,dp[j]);
        }
    }
    
    //for(int i=1;i<=M;i++) cout<<i<<" "<<dp[i]<<endl;
    
    ans=min(ans,dp[M]);
    
    cout<<ans<<endl;
    
}