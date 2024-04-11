#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2005,INF=1<<30;
int dp[MAX][MAX];
char S[MAX][MAX];
string ans;
vector<pair<int,int>> start;
int N;

void BFS(){
    for(int now=start[0].first+start[0].second;now<N+N;now++){
        vector<pair<char,pair<int,int>>> to;
        for(int i=0;i<start.size();i++){
            int a=start[i].first,b=start[i].second;
            if(a+1<=N){
                to.push_back({S[a+1][b],{a+1,b}});
            }
            if(b+1<=N){
                to.push_back({S[a][b+1],{a,b+1}});
            }
        }
        sort(all(to));
        to.erase(unique(all(to)),to.end());
        ans+=to[0].first;
        start.clear();
        
        for(int i=0;i<to.size();i++){
            if(to[i].first==to[0].first){
                start.push_back(to[i].second);
            }
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int K;cin>>N>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>S[i+1][j+1];
        }
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            dp[i][j]=INF;
        }
    }
    if(S[1][1]=='a') dp[1][1]=0;
    else dp[1][1]=1;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(S[i][j]=='a'){
                dp[i][j]=min({dp[i][j],dp[i-1][j],dp[i][j-1]});
            }else{
                dp[i][j]=min({dp[i][j],dp[i-1][j]+1,dp[i][j-1]+1});
            }
        }
    }
    
    for(int s=2;s<=N+N;s++){
        bool ok=false;
        for(int i=1;i<=N;i++){
            if(s-i>=1&&s-i<=N&&dp[i][s-i]<=K) ok=true;
        }
        if(!ok){
            s--;
            for(int j=2;j<=s;j++){
                ans+='a';
            }
            
            for(int i=1;i<=N;i++){
                if(s-i>=1&&s-i<=N&&dp[i][s-i]<=K) start.push_back({i,s-i});
            }
            
            if(start.size()==0){
                ans+=S[1][1];
                start.push_back({1,1});
            }
            BFS();
            
            cout<<ans<<endl;
            return 0;
        }
        
        if(s==N+N){
            for(int j=2;j<=s;j++){
                ans+='a';
            }
            cout<<ans<<endl;
            return 0;
        }
    }
    
}