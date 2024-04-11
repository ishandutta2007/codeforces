#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        string S;cin>>S;
        sort(all(S));
        
        if(S[0]!=S[M-1]||N==M){
            cout<<S[M-1]<<"\n";
        }else{
            string ans;
            ans+=S[0];
            if(S[M]==S[N-1]){
                int k=(N+M-1)/M;
                k--;
                for(int i=0;i<k;i++) ans+=S[M];
                cout<<ans<<"\n";
            }else{
                cout<<ans;
                cout<<S.substr(M)<<"\n";
            }
        }
    }
}