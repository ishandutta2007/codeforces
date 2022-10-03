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

vector<int> from[MAX];
int now[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        for(int i=0;i<N;i++){
            from[i].clear();
            now[i]=0;
        }
        
        vector<int> ans;
        
        for(int i=0;i<M;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            from[b].push_back(a);
        }
        
        for(int i=0;i<N;i++){
            bool c1=false,c2=false;
            for(int a:from[i]){
                if(now[a]==1) c1=1;
                if(now[a]==2) c2=1;
            }
            if(c2) ans.push_back(i);
            else if(c1) now[i]=2;
            else now[i]=1;
        }
        
        cout<<si(ans)<<"\n";
        for(int a:ans) cout<<a+1<<" ";
        cout<<"\n";
    }
}