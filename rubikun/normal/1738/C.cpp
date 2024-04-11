#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=105,INF=1<<30;

bool seen[MAX][MAX][2][2];
bool dp[MAX][MAX][2][2];

bool solve(int a,int b,int t,int r){
    if(seen[a][b][t][r]) return dp[a][b][t][r];
    if(a==0&&b==0){
        if(t==0){
            if(r==0) return true;
            else return false;
        }else{
            if(r==0) return false;
            else return true;
        }
    }
    
    seen[a][b][t][r]=true;
    
    if(t==0){
        if(a){
            if(!solve(a-1,b,t^1,r)) return dp[a][b][t][r]=true;
        }
        if(b){
            if(!solve(a,b-1,t^1,r^1)) return dp[a][b][t][r]=true;
        }
        return dp[a][b][t][r]=false;
    }else{
        if(a){
            if(!solve(a-1,b,t^1,r)) return dp[a][b][t][r]=true;
        }
        if(b){
            if(!solve(a,b-1,t^1,r)) return dp[a][b][t][r]=true;
        }
        return dp[a][b][t][r]=false;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        memset(seen,0,sizeof(seen));
        memset(dp,0,sizeof(dp));
        
        int N;cin>>N;
        int a=0,b=0;
        for(int i=0;i<N;i++){
            int x;cin>>x;
            x=abs(x);
            if(x%2==0) a++;
            else b++;
        }
        
        bool res=solve(a,b,0,0);
        if(res) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
}