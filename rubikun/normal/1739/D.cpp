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
int h[MAX];
int mid;
int cn;

void solve(int u){
    for(int to:G[u]){
        solve(to);
        if(h[to]==mid-1){
            if(u) cn++;
        }else{
            chmax(h[u],h[to]+1);
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        for(int i=0;i<N;i++){
            G[i].clear();
            h[i]=0;
        }
        for(int i=1;i<N;i++){
            int p;cin>>p;p--;
            G[p].push_back(i);
        }
        
        int left=0,right=N-1;
        while(right-left>1){
            mid=(left+right)/2;
            for(int i=0;i<N;i++){
                h[i]=0;
            }
            cn=0;
            solve(0);
            
            if(cn<=K) right=mid;
            else left=mid;
        }
        
        cout<<right<<"\n";
    }
}