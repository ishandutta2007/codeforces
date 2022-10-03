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
    vector<vector<int>> A(N,vector<int>(N));
    vector<int> ans(N);
    int n=N-1;
    for(int i=0;i<N;i++){
        vector<int> cn(N+1);
        for(int j=0;j<N;j++){
            int x;cin>>x;
            cn[x]++;
        }
        int ma=-1;
        for(int j=1;j<=N;j++){
            if(cn[j]>=2) ma=j;
        }
        if(ma!=-1){
            ans[i]=ma;
        }else{
            ans[i]=n;n++;
        }
    }
    
    for(int a:ans) cout<<a<<" ";
    cout<<endl;
}