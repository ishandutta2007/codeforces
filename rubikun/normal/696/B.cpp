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
const int mod=998244353,MAX=300005,INF=1<<30;

vector<int> G[MAX];

int sz[MAX];

void make(int u){
    sz[u]=1;
    for(int to:G[u]){
        make(to);
        sz[u]+=sz[to];
    }
}

double ans[MAX];

void solve(int u){
    if(u==0) ans[u]=1;
    double sum=0;
    for(int to:G[u]){
        sum+=(double)(sz[to])/2;
    }
    
    for(int to:G[u]){
        ans[to]=ans[u]+(sum-(double)sz[to]/2)+1;
        solve(to);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=1;i<N;i++){
        int p;cin>>p;p--;
        G[p].push_back(i);
    }
    
    make(0);
    solve(0);
    
    for(int i=0;i<N;i++) cout<<fixed<<setprecision(25)<<ans[i]<<" ";
    cout<<"\n";
}