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
    vector<int> p(N);
    vector<vector<int>> ans(N,vector<int>(N));
    
    for(int i=0;i<N;i++){
        cin>>p[i];
        ans[i][i]=p[i];
    }
    
    for(int t=0;t<N-1;t++){
        int id=-1;
        for(int j=0;j<N-t;j++){
            if(ans[j+t][j]==t+1){
                id=j;
            }
        }
        
        for(int j=0;j<id;j++){
            ans[j+t+1][j]=ans[j+t][j];
        }
        
        for(int j=id+1;j<N-t;j++){
            ans[j+t][j-1]=ans[j+t][j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}