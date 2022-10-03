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

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        bool ok=true;
        for(int i=0;i<N;i++){
            if(A[i]!=A[N-1-i]) ok=false;
        }
        if(ok){
            cout<<"YES\n";
        }else{
            vector<int> X;
            for(int t=0;t<N;t++){
                if(A[t]!=A[N-1-t]){
                    X.push_back(A[t]);
                    X.push_back(A[N-1-t]);
                    break;
                }
            }
            for(int a:X){
                vector<int> B;
                for(int i=0;i<N;i++) if(A[i]!=a) B.push_back(A[i]);
                bool f=true;
                for(int i=0;i<si(B);i++){
                    if(B[i]!=B[si(B)-1-i]) f=false;
                }
                if(f) ok=true;
            }
            if(ok) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}