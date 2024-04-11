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
const int mod=998244353,MAX=1005;
const ll INF=1LL<<60;

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N);
        set<ll> SE;
        for(int i=0;i<N;i++){
            cin>>A[i];
            SE.insert(A[i]);
        }
        sort(all(A));
        if(A[0]>=2){
            cout<<"YES\n";
        }else if(A[0]==1){
            bool f=true;
            for(int i=0;i+1<N;i++) if(A[i]+1==A[i+1]) f=false;
            if(f) cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            bool f=true;
            for(int i=0;i<N;i++) if(A[i]==1) f=false;
            if(f) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}