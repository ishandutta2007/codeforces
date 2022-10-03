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
//const ll INF=1LL<<60;

struct edge{
    int from;
    int to;
    int cost;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int L,R;cin>>L>>R;
    int S=(R-L)+1;
    
    vector<edge> ans;
    
    for(int i=0;i<23;i++){
        for(int j=i+1;j<23;j++){
            if(i<=1) ans.push_back({i,j,1});
            else ans.push_back({i,j,min(1000000,1<<(i-1))});
        }
    }
    
    for(int i=22;i>=1;i--){
        if(S>(1<<(i-1))){
            S-=(1<<(i-1));
            ans.push_back({i,23,S});
        }
    }
    
    ans.push_back({0,23,1});
    
    cout<<"YES"<<endl;
    
    if(L>=2){
        ans.push_back({23,24,L-1});
        cout<<25<<" "<<si(ans)<<endl;
        for(auto e:ans){
            cout<<e.from+1<<" "<<e.to+1<<" "<<e.cost<<endl;
        }
    }else{
        cout<<24<<" "<<si(ans)<<endl;
        for(auto e:ans){
            cout<<e.from+1<<" "<<e.to+1<<" "<<e.cost<<endl;
        }
    }
}