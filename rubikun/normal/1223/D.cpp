#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    while(Q){
        int N;cin>>N;
        int cnt=0;
        vector<pair<int,int>> P(N+1,{INF,-1});
        
        for(int i=0;i<N;i++){
            int a;cin>>a;
            if(P[a]==make_pair(INF,-1)) cnt++;
            
            P[a].first=min(P[a].first,i+1);
            P[a].second=max(P[a].second,i+1);
            
        }
        
        vector<int> dp(N+3,INF);
        dp[0]=-1;
        int maxi=1,right=-1,now=0;
        
        for(int i=0;i<N+1;i++){
            if(P[i]==make_pair(INF,-1)) continue;
            if(right<P[i].first){
                now++;
                right=P[i].second;
            }else{
                maxi=max(maxi,now);
                now=1;
                right=P[i].second;
            }
        }
        
        maxi=max(maxi,now);
        
        cout<<cnt-maxi<<endl;
        
        Q--;
        
    }
}