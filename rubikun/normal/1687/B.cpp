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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    int N,M;cin>>N>>M;
    vector<pair<int,int>> E(M);
    for(int i=0;i<M;i++){
        string S;
        for(int j=0;j<M;j++){
            if(i==j) S+='1';
            else S+='0';
        }
        cout<<"? "<<S<<endl;
        int res;cin>>res;
        E[i]=mp(res,i);
    }
    
    sort(all(E));
    
    int ans=0;
    
    string use(M,'0');
    
    for(int i=0;i<M;i++){
        use[E[i].se]='1';
        cout<<"? "<<use<<endl;
        int res;cin>>res;
        if(ans+E[i].fi==res){
            ans=res;
        }else{
            use[E[i].se]='0';
        }
    }
    
    cout<<"! "<<ans<<endl;
}