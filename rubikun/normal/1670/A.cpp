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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        int cn=0;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            int x;cin>>x;
            if(x<0) cn++;
            A[i]=abs(x);
        }
        for(int i=0;i<cn;i++) A[i]*=(-1);
        bool f=true;
        for(int i=0;i+1<N;i++){
            f&=(A[i]<=A[i+1]);
        }
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}