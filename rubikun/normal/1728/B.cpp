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
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        if(N%2==0){
            for(int i=N-2;i>=1;i--) cout<<i<<" ";
            cout<<N-1<<" "<<N<<"\n";
        }else{
            cout<<1<<" ";
            for(int i=N-2;i>=2;i--) cout<<i<<" ";
            cout<<N-1<<" "<<N<<"\n";
        }
    }
    
}