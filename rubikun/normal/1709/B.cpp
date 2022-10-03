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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q;cin>>N>>Q;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    vector<ll> ruiL(N),ruiR(N);
    for(int i=N-2;i>=0;i--){
        ruiL[i]=ruiL[i+1]+max(0LL,A[i+1]-A[i]);
    }
    for(int i=1;i<N;i++){
        ruiR[i]=ruiR[i-1]+max(0LL,A[i-1]-A[i]);
    }
    while(Q--){
        int l,r;cin>>l>>r;l--;r--;
        if(l<r){
            cout<<ruiR[r]-ruiR[l]<<"\n";
        }else if(l>r){
            cout<<ruiL[r]-ruiL[l]<<"\n";
        }else{
            cout<<0<<"\n";
        }
    }
}