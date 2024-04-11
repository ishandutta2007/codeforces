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
const int mod=998244353,MAX=5005;
const ll INF=1LL<<55;

ll dis(vector<int> &A,vector<int> &B){
    vector<int> X,Y;
    int N=si(A);
    for(int i=0;i<N;i++){
        if(A[i]) X.push_back(i);
        if(B[i]) Y.push_back(i);
    }
    if(si(X)!=si(Y)) return INF;
    ll ans=0;
    for(int i=0;i<si(X);i++){
        ans+=abs(X[i]-Y[i]);
    }
    return ans;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        int sum=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            A[i]&=1;
            sum+=A[i];
        }
        ll ans=INF;
        vector<int> B(N);
        for(int i=0;i<N;i++){
            B[i]=(i&1);
        }
        chmin(ans,dis(A,B));
        for(int i=0;i<N;i++){
            B[i]=1-B[i];
        }
        chmin(ans,dis(A,B));
        
        if(ans==INF) ans=-1;
        
        cout<<ans<<"\n";
    }
}