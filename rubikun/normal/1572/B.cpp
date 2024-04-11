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
const int mod=1000000007,MAX=3005,INF=1<<29;

vector<int> ans;

void yes(){
    cout<<"YES\n";
    cout<<si(ans)<<"\n";
    for(int a:ans) cout<<a+1<<" ";
    cout<<"\n";
    ans.clear();
}

void no(){
    cout<<"NO\n";
    ans.clear();
}

void solve(){
    int N;cin>>N;
    vector<int> A(N+1);
    for(int i=0;i<N;i++){
        cin>>A[i+1];
        A[i+1]^=A[i];
    }
    if(A.back()){
        no();
        return;
    }
    
    if(N&1){
        for(int i=0;i<=N-3;i+=2) ans.push_back(i);
        for(int i=N-3;i>=0;i-=2) ans.push_back(i);
        yes();
        return;
    }
    
    int zero=-1;
    for(int i=1;i<N;i+=2) if(A[i]==0) zero=i;
    if(zero==-1){
        no();
        return;
    }
    for(int i=zero;i<=N-3;i+=2) ans.push_back(i);
    for(int i=0;i<=N-4;i+=2) ans.push_back(i);
    for(int i=zero-3;i>=0;i-=2) ans.push_back(i);
    yes();
    return;
    
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        solve();
    }
}