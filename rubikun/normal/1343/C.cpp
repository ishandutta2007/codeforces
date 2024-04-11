#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N);
        ll sum=0;
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<N;){
            int j=i+1;
            ll ma=A[i];
            while(j<N&&A[i]*A[j]>=1){
                chmax(ma,A[j]);
                j++;
            }
            sum+=ma;
            i=j;
        }
        cout<<sum<<"\n";
    }
}