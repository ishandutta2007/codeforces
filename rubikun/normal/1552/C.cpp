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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<61;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<pair<int,int>> A(N);
        vector<int> used(2*N);
        for(int i=0;i<M;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            if(a>b) swap(a,b);
            A[i]=mp(a,b);
            used[a]=true;
            used[b]=true;
        }
        vector<int> B;
        for(int i=0;i<2*N;i++) if(!used[i]) B.push_back(i);
        for(int i=M;i<N;i++){
            A[i]=mp(B[i-M],B[i-M+si(B)/2]);
        }
        
        int ans=0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(A[i].fi<A[j].fi&&A[j].fi<A[i].se&&A[i].se<A[j].se) ans++;
            }
        }
        
        cout<<ans<<"\n";
    }
}