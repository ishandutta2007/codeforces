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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<vector<int>> can(2,vector<int>(N)),result(2,vector<int>(N)),use(2,vector<int>()),cnt(2,vector<int>(N));
    
    for(int i=0;i<2;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int x;cin>>x;
            use[i].push_back(x);
            can[i][x]=1;
        }
        sort(all(use[i]));
    }
    
    for(int i=0;i<2;i++){
        for(int j=N-1;j>=1;j--){
            if(can[i][N-j]){
                result[i][j]=1;
                for(int a:use[i^1]){
                    cnt[i^1][(j-a+N)%N]++;
                }
            }
        }
    }
    
    for(int t=0;t<2*N;t++){
        for(int i=0;i<2;i++){
            for(int j=N-1;j>=1;j--){
                if(result[i][j]) continue;
                
                if(cnt[i][j]==si(use[i])){
                    result[i][j]=2;
                    
                    for(int a:use[i^1]){
                        if(result[i^1][(j-a+N)%N]) continue;
                        
                        result[i^1][(j-a+N)%N]=1;
                        
                        for(int b:use[i]){
                            cnt[i][((j-a+N)%N-b+N)%N]++;
                        }
                    }
                }
            }
        }
    }
    
    for(int i=0;i<2;i++){
        for(int j=1;j<=N-1;j++){
            if(result[i][j]==0) cout<<"Loop ";
            else if(result[i][j]==1) cout<<"Win ";
            else cout<<"Lose ";
        }
        cout<<"\n";
    }
    
}