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
const int mod=998244353,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> x,y;
        for(int i=0;i<N;i++){
            int a,b;cin>>a>>b;
            x.push_back(a);
            y.push_back(b);
        }
        x.push_back(0);
        y.push_back(0);
        sort(all(x));
        sort(all(y));
        int ans=0;
        ans+=-x.front();
        ans+=-y.front();
        ans+=x.back();
        ans+=y.back();
        ans*=2;
        cout<<ans<<"\n";
    }
}