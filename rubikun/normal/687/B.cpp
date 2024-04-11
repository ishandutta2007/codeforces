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
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    vector<int> SE;
    
    for(int i=2;i*i<=K;i++){
        int c=1;
        while(K%i==0){
            c*=i;
            K/=i;
        }
        if(c>1) SE.push_back(c);
    }
    
    if(K>1) SE.push_back(K);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<si(SE);j++){
            if(SE[j]==0) continue;
            if(A[i]%SE[j]==0) SE[j]=0;
        }
    }
    
    bool ok=true;
    for(int j=0;j<si(SE);j++) if(SE[j]) ok=false;
    
    if(ok) cout<<"Yes\n";
    else cout<<"No\n";
}