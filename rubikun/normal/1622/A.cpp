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
const int mod=1000000007,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        vector<ll> A(3);
        for(int i=0;i<3;i++) cin>>A[i];
        sort(all(A));
        if(A[0]+A[1]==A[2]) cout<<"Yes\n";
        else if(A[0]==A[1]&&A[2]%2==0) cout<<"Yes\n";
        else if(A[1]==A[2]&&A[0]%2==0) cout<<"Yes\n";
        else cout<<"No\n";
    }
}