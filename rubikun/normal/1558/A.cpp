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
const int mod=998244353,MAX=200005;
const ll INF=1LL<<62;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int a,b;cin>>a>>b;
        int N=a+b;
        set<int> ans;
        if(N&1){
            for(int t=0;t<=a;t++){
                if(t>(N+1)/2||(a-t)>N/2) continue;
                ans.insert(a-t+(N+1)/2-t);
            }
            for(int t=0;t<=a;t++){
                if(t>N/2||(a-t)>(N+1)/2) continue;
                ans.insert(a-t+N/2-t);
            }
        }else{
            for(int t=0;t<=a;t++){
                if(t>N/2||(a-t)>N/2) continue;
                ans.insert(a-t+N/2-t);
            }
        }
        
        cout<<si(ans)<<"\n";
        for(int a:ans) cout<<a<<" ";
        cout<<"\n";
    }
}