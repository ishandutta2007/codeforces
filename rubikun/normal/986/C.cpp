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
const int mod=1000000007,MAX=4200005,INF=1<<30;
bool aru[MAX],check[MAX*2];
int N;
void DFS(int u){
    if(check[u]) return;
    check[u]=1;
    
    if(u<MAX){
        DFS((1<<N)-1-u+MAX);
    }else{
        u-=MAX;
        for(int i=0;i<N;i++){
            if(u&(1<<i)) DFS((u^(1<<i))+MAX);
        }
        if(aru[u]) DFS(u);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int M;cin>>N>>M;
    vector<int> A(M);
    for(int i=0;i<M;i++){
        cin>>A[i];
        aru[A[i]]=1;
    }
    int ans=0;
    
    for(int bit=0;bit<(1<<N);bit++){
        if(aru[bit]&&check[bit]==0){
            ans++;
            DFS(bit);
        }
    }
    
    cout<<ans<<endl;
}