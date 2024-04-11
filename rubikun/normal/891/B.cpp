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
    vector<int> A(N),id(N),B(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        id[i]=i;
    }
    
    sort(all(id),[&](int a,int b){
        return A[a]<A[b];
    });
    
    for(int i=0;i<N;i++){
        B[id[i]]=A[id[(i+1)%N]];
    }
    
    for(int i=0;i<N;i++) cout<<B[i]<<" ";
    cout<<endl;
}