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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,U;cin>>N>>U;
    vector<int> E(N);
    for(int i=0;i<N;i++){
        cin>>E[i];
    }
    
    double ans=-1;
    
    for(int i=0;i+2<N;i++){
        int c=upper_bound(all(E),E[i]+U)-E.begin()-1;
        int a=i,b=i+1;
        if(c<=b) continue;
        chmax(ans,(double)(E[c]-E[b])/(double)(E[c]-E[a]));
    }
    
    if(ans==-1) cout<<-1<<endl;
    else cout<<fixed<<setprecision(30)<<ans<<endl;
}