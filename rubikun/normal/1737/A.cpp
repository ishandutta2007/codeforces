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
        int N,K;cin>>N>>K;
        vector<int> cn(26);
        string S;cin>>S;
        for(char c:S) cn[c-'a']++;
        
        string ans;
        
        for(int t=0;t<K;t++){
            int ne=0;
            for(int i=0;i<N/K;i++){
                if(cn[ne]){
                    cn[ne]--;
                    ne++;
                }else{
                    break;
                }
            }
            ans+=char('a'+ne);
        }
        
        cout<<ans<<"\n";
    }
}