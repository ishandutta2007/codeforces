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
    vector<int> A(N),B(N),id(N),ans(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    
    iota(all(id),0);
    sort(all(id),[&](int a,int b){
        return B[a]<B[b];
    });
    
    sort(all(A));
    reverse(all(A));
    
    for(int i=0;i<N;i++){
        ans[id[i]]=A[i];
    }
    
    for(int i=0;i<N;i++) cout<<ans[i]<<" ";
    cout<<endl;
}