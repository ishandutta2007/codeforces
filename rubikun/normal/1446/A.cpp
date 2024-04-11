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

void solve(){
    int N;ll W;cin>>N>>W;
    vector<pair<ll,int>> w(N);
    for(int i=0;i<N;i++){
        cin>>w[i].fi;
        w[i].se=i;
    }
    sort(all(w));
    
    for(int i=0;i<N;i++){
        if(w[i].fi>=(W+1)/2&&w[i].fi<=W){
            cout<<1<<"\n";
            cout<<w[i].se+1<<"\n";
            return;
        }
    }
    
    ll sum=0;
    for(int i=0;i<N;i++){
        sum+=w[i].fi;
        if(sum>=(W+1)/2&&sum<=W){
            cout<<i+1<<"\n";
            for(int j=0;j<=i;j++) cout<<w[j].se+1<<" ";
            cout<<"\n";
            
            return;
        }
    }
    
    cout<<-1<<"\n";
    return;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        solve();
    }
    
}