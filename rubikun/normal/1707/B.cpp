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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

void solve(){
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    vector<int> B;
    int cn=0;
    for(int i=0;i<N-1;i++){
        if(A[i+1]-A[i]==0) cn++;
        else B.push_back(A[i+1]-A[i]);
    }
    sort(all(B));
    
    while(cn+si(B)>1){
        if(si(B)==0){
            cout<<0<<"\n";
            return;
        }
        int nx=0;
        if(cn==0){
            vector<int> C;
            for(int i=0;i<si(B)-1;i++){
                if(B[i+1]-B[i]==0) nx++;
                else C.push_back(B[i+1]-B[i]);
            }
            sort(all(C));
            cn=nx;
            B=C;
        }else if(cn>=1){
            nx=cn-1;
            vector<int> C={B[0]};
            for(int i=0;i<si(B)-1;i++){
                if(B[i+1]-B[i]==0) nx++;
                else C.push_back(B[i+1]-B[i]);
            }
            sort(all(C));
            cn=nx;
            B=C;
        }
    }
    
    if(cn==0) cout<<B[0]<<"\n";
    else cout<<0<<"\n";
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