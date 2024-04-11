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
    vector<int> A(N+1),B(N);
    for(int i=0;i<N;i++) cin>>A[i+1];
    for(int i=0;i<N;i++) B[i]=A[i+1]-A[i];
    
    vector<int> ans;
    
    for(int k=1;k<=N;k++){
        bool ok=true;
        
        for(int i=0;i<N;i++){
            if(B[i]!=B[i%k]) ok=false;
        }
        
        if(ok) ans.push_back(k);
    }
    
    cout<<si(ans)<<endl;
    for(int a:ans) cout<<a<<" ";
    cout<<endl;
}