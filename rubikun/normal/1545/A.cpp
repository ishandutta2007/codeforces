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
const int mod=1000000007,MAX=200005,INF=1<<28;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        map<pair<int,int>,int> MA;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
            MA[mp(A[i],i&1)]++;
        }
        vector<int> B=A;
        sort(all(B));
        for(int i=0;i<N;i++){
            MA[mp(B[i],i&1)]--;
        }
        bool ok=true;
        
        for(auto a:MA) if(a.se) ok=false;
        
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}