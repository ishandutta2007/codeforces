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
const int mod=998244353,MAX=3005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,A,B;cin>>N>>A>>B;
        int ans=A/(B+1);
        vector<int> X(B+1,ans);
        int rem=A-(B+1)*ans;
        for(int i=0;i<rem;i++) X[i]++;
        for(int i=0;i<si(X);i++){
            if(i) cout<<'B';
            for(int j=0;j<X[i];j++) cout<<'R';
        }
        cout<<"\n";
    }
}