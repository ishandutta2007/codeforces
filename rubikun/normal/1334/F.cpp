#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<19;
const ll INF=1LL<<60;

ll bit[MAX+1],N;

//1-indexed

ll sum(int i){
    ll s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}

//st=sum(t)-sum(s-1)

void add(int i,ll x){
    while(i<=N){
        bit[i]+=x;
        i+=i&-i;
    }
}

ll dp[MAX];
vector<int> when[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<=N;i++) dp[i]=INF;
    vector<ll> A(N+1),p(N+1);
    for(int i=1;i<=N;i++){
        cin>>A[i];
        when[A[i]].push_back(i);
    }
    for(int i=1;i<=N;i++){
        cin>>p[i];
        add(i,p[i]);
    }
    
    int M;cin>>M;
    vector<ll> B(M);
    for(int i=0;i<M;i++) cin>>B[i];
    
    for(int a:when[B[0]]){
        dp[a]=sum(a-1);
    }
    
    for(int i=0;i<=B[0];i++){
        for(int a:when[i]){
            if(p[a]>0) add(a,-p[a]);
        }
    }
    
    for(int i=1;i<M;i++){
        int j=0;
        for(int k=0;k<when[B[i]].size();k++){
            int a=when[B[i]][k];;
            if(k){
                int b=when[B[i]][k-1];
                dp[a]=min(dp[a],dp[b]+sum(a-1)-sum(b-1));
            }
            
            while(j<when[B[i-1]].size()&&when[B[i-1]][j]<a){
                int b=when[B[i-1]][j];
                dp[a]=min(dp[a],dp[b]+sum(a-1)-sum(b));
                j++;
            }
        }
        
        for(int j=B[i-1]+1;j<=B[i];j++){
            for(int a:when[j]){
                if(p[a]>0) add(a,-p[a]);
            }
        }
    }
    
    ll ans=INF;
    
    for(int a:when[B[M-1]]){
        ans=min(ans,dp[a]+sum(N)-sum(a));
    }
    
    if(ans>=INF/2) cout<<"NO\n";
    else{
        cout<<"YES\n";
        cout<<ans<<"\n";
    }
    
    //cout<<ans<<endl;
}