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
        vector<int> A(N),now(N);
        set<pair<int,int>> SE;
        for(int i=0;i<N;i++){
            cin>>A[i];
            now[i]=A[i];
            SE.insert(mp(now[i],i));
        }
        int ans=INF;
        while(1){
            auto l=SE.begin();
            auto r=SE.end();r--;
            chmin(ans,(*r).fi-(*l).fi);
            int i=(*r).se;
            SE.erase(r);
            int a=A[i],b=now[i]-1;
            if(b<0) break;
            int x=(a+b+1)/(b+1);
            if(x>K) break;
            now[i]=A[i]/x;
            SE.insert(mp(now[i],i));
        }
        
        cout<<ans<<"\n";
    }
}