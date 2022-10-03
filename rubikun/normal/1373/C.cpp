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
const int mod=1000000007,MAX=5005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int N=si(S);
        vector<int> wh(N+3,INF);
        
        int cur=0;
        for(int i=0;i<N;i++){
            if(S[i]=='+') cur++;
            else cur--;
            if(cur<0){
                chmin(wh[-cur-1],i+1);
            }
        }
        
        ll ans=N;
        
        for(int i=0;;i++){
            if(wh[i]==INF) break;
            ans+=wh[i];
        }
        
        cout<<ans<<"\n";
    }
}