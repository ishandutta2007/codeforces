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
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<int> ok(N,1);
        for(int i=0;i<M;i++){
            int a,b,c;cin>>a>>b>>c;
            a--;b--;c--;
            ok[b]=false;
        }
        
        for(int i=0;i<N;i++){
            if(ok[i]){
                for(int j=0;j<N;j++){
                    if(i==j) continue;
                    cout<<i+1<<" "<<j+1<<"\n";
                }
                break;
            }
        }
    }
}