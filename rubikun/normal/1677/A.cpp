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
const int mod=998244353,MAX=5005;
const ll INF=1LL<<61;
int L[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> P(N);
        for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) L[i][j]=0;
        for(int i=0;i<N;i++){
            cin>>P[i];P[i]--;
        }
        for(int j=0;j<N;j++){
            int cn=0;
            for(int i=0;i<j;i++){
                L[i][j]=cn;
                if(P[i]<P[j]) cn++;
            }
        }
        ll ans=0;
        for(int i=0;i<N;i++){
            ll cn=0;
            for(int j=N-1;j>i;j--){
                ans+=cn*L[i][j];
                if(P[i]>P[j]) cn++;
            }
        }
        
        cout<<ans<<"\n";
    }
}