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
        string S;cin>>S;
        int K;cin>>K;
        vector<int> ng(26);
        for(int i=0;i<K;i++){
            char c;cin>>c;
            ng[c-'a']=true;
        }
        
        int ans=0;
        
        int la=N;
        
        for(int i=N-1;i>=0;i--){
            if(la!=N) chmax(ans,la-i);
            if(ng[S[i]-'a']){
                la=i;
            }
        }
        
        cout<<ans<<"\n";
    }
}