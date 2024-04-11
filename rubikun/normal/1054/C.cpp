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
    
    int N;cin>>N;
    vector<int> l(N),r(N),ans(N);
    
    for(int i=0;i<N;i++) cin>>l[i];
    for(int i=0;i<N;i++) cin>>r[i];
    
    for(int t=N;t>=1;t--){
        for(int i=0;i<N;i++){
            if(l[i]==0&&r[i]==0&&ans[i]==0) ans[i]=t;
        }
        int cnt=0;
        for(int i=0;i<N;i++){
            if(ans[i]==t) cnt++;
            else if(ans[i]==0) l[i]-=cnt;
        }
        cnt=0;
        for(int i=N-1;i>=0;i--){
            if(ans[i]==t) cnt++;
            else if(ans[i]==0) r[i]-=cnt;
        }
    }
    
    bool ok=true;
    
    for(int i=0;i<N;i++) if(ans[i]==0) ok=false;
    
    if(!ok) cout<<"NO\n";
    else{
        cout<<"YES\n";
        for(int i=0;i<N;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}