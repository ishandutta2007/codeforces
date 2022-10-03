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
    
    int QQ;cin>>QQ;
    vector<int> ans,to(500001);
    vector<pair<int,int>> Q(QQ);
    for(int q=0;q<QQ;q++){
        int t;cin>>t;
        if(t==1){
            int x;cin>>x;
            Q[q]=mp(x,-1);
        }else{
            int x,y;cin>>x>>y;
            Q[q]=mp(x,y);
        }
    }
    iota(all(to),0);
    for(int q=QQ-1;q>=0;q--){
        if(Q[q].se==-1){
            ans.push_back(to[Q[q].fi]);
        }else{
            if(Q[q].fi==Q[q].se) continue;
            to[Q[q].fi]=to[Q[q].se];
        }
    }
    
    reverse(all(ans));
    
    for(int a:ans) cout<<a<<" ";
    cout<<endl;
}