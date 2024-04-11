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
const int mod=998244353,MAX=1005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int a,b;cin>>a>>b;
        int ans=b-a;
        for(int i=0;i<=b;i++){
            int x=a+i;
            if((x&b)==x) chmin(ans,i+1);
        }
        for(int i=0;i<=b;i++){
            int x=b+i;
            if((a&x)==a) chmin(ans,i+1);
        }
        
        cout<<ans<<"\n";
    }
}