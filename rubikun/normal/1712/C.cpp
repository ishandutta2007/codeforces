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

vector<int> pos[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<=N;i++) pos[i].clear();
        for(int i=0;i<N;i++){
            cin>>A[i];
            pos[A[i]].push_back(i);
        }
        
        int ans=0;
        set<int> ng;
        for(int i=0;i+1<N;i++) if(A[i]>A[i+1]) ng.insert(i);
        
        while(!ng.empty()){
            int x=*ng.begin();
            ans++;
            for(int a:pos[A[x]]){
                if(ng.count(a-1)) ng.erase(a-1);
                if(ng.count(a)) ng.erase(a);
                A[a]=0;
                if(a&&A[a-1]>A[a]) ng.insert(a-1);
            }
        }
        
        cout<<ans<<"\n";
    }
}