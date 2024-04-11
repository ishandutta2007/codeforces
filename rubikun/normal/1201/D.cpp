#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17;
const ll INF=1LL<<45;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M,K,Q;cin>>N>>M>>K>>Q;
    vector<pair<int,int>> T(K);
    vector<int> C(Q);
    
    for(int i=0;i<K;i++){
        cin>>T[i].first>>T[i].second;
    }
    for(int i=0;i<Q;i++){
        cin>>C[i];
    }
    
    sort(all(T));
    sort(all(C));
    
    int end=T[K-1].first;
    
    ll dp[end+1][4];//i,,
    
    for(int i=0;i<end+1;i++){
        for(int j=0;j<4;j++){
            dp[i][j]=INF;
        }
    }
    
    for(int j=0;j<4;j++){
        dp[1][j]=0;
    }
    
    int a,b,c,d;//
    a=b=c=d=1;
    
    for(int i=1;i<=end-1;i++){
        int a2=a,b2=b,c2=c,d2=d;
        auto it=lower_bound(all(T),make_pair(i,-1));
        auto it2=lower_bound(all(T),make_pair(i+1,-1));
        if(it==it2){
            if(i==1){
                a2=b2=c2=d2=C[0];
                for(int j=0;j<4;j++){
                    dp[2][j]=dp[1][j]+1+C[0]-1;
                }
            }else{
                for(int j=0;j<4;j++){
                    dp[i+1][j]=dp[i][j]+1;
                }
            }
        }else{
            it2--;
            int left=(*it).second,right=(*it2).second;
            auto x1=lower_bound(all(C),left);
            auto x2=lower_bound(all(C),left);
            auto x3=lower_bound(all(C),right);
            auto x4=lower_bound(all(C),right);
            
            if(x1!=C.begin()) x1--;
            if(x2==C.end()) x2--;
            if(x3!=C.begin()) x3--;
            if(x4==C.end()) x4--;
            a2=(*x1);b2=(*x2);c2=(*x3);d2=(*x4);
            
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]+abs(right-a)+abs(right-left)+abs(left-a2));
            dp[i+1][0]=min(dp[i+1][0],dp[i][1]+abs(right-b)+abs(right-left)+abs(left-a2));
            dp[i+1][0]=min(dp[i+1][0],dp[i][2]+abs(right-c)+abs(right-left)+abs(left-a2));
            dp[i+1][0]=min(dp[i+1][0],dp[i][3]+abs(right-d)+abs(right-left)+abs(left-a2));
            
            dp[i+1][1]=min(dp[i+1][1],dp[i][0]+abs(right-a)+abs(right-left)+abs(left-b2));
            dp[i+1][1]=min(dp[i+1][1],dp[i][1]+abs(right-b)+abs(right-left)+abs(left-b2));
            dp[i+1][1]=min(dp[i+1][1],dp[i][2]+abs(right-c)+abs(right-left)+abs(left-b2));
            dp[i+1][1]=min(dp[i+1][1],dp[i][3]+abs(right-d)+abs(right-left)+abs(left-b2));
            
            dp[i+1][2]=min(dp[i+1][2],dp[i][0]+abs(left-a)+abs(right-left)+abs(right-c2));
            dp[i+1][2]=min(dp[i+1][2],dp[i][1]+abs(left-b)+abs(right-left)+abs(right-c2));
            dp[i+1][2]=min(dp[i+1][2],dp[i][2]+abs(left-c)+abs(right-left)+abs(right-c2));
            dp[i+1][2]=min(dp[i+1][2],dp[i][3]+abs(left-d)+abs(right-left)+abs(right-c2));
            
            dp[i+1][3]=min(dp[i+1][3],dp[i][0]+abs(left-a)+abs(right-left)+abs(right-d2));
            dp[i+1][3]=min(dp[i+1][3],dp[i][1]+abs(left-b)+abs(right-left)+abs(right-d2));
            dp[i+1][3]=min(dp[i+1][3],dp[i][2]+abs(left-c)+abs(right-left)+abs(right-d2));
            dp[i+1][3]=min(dp[i+1][3],dp[i][3]+abs(left-d)+abs(right-left)+abs(right-d2));
            
            for(int j=0;j<4;j++){
                dp[i+1][j]++;
            }
        }
        
        a=a2;b=b2;c=c2;d=d2;
    }
    
    auto it=lower_bound(all(T),make_pair(end,-1));
    auto it2=lower_bound(all(T),make_pair(end+1,-1));
    
    it2--;
    int left=(*it).second,right=(*it2).second;
    
    ll ans=INF;
    
    ans=min(ans,dp[end][0]+abs(left-a)+abs(right-left));
    ans=min(ans,dp[end][0]+abs(right-a)+abs(right-left));
    
    ans=min(ans,dp[end][1]+abs(left-b)+abs(right-left));
    ans=min(ans,dp[end][1]+abs(right-b)+abs(right-left));
    
    ans=min(ans,dp[end][2]+abs(left-c)+abs(right-left));
    ans=min(ans,dp[end][2]+abs(right-c)+abs(right-left));
    
    ans=min(ans,dp[end][3]+abs(left-d)+abs(right-left));
    ans=min(ans,dp[end][3]+abs(right-d)+abs(right-left));
    
    cout<<ans<<endl;
    
}