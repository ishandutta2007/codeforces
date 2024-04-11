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
    
    int N;cin>>N;
    vector<pair<int,int>> E(N-1);
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        E[i]=mp(a,b);
    }
    vector<int> c(N);
    for(int i=0;i<N;i++){
        cin>>c[i];
    }
    
    vector<int> hin(N);
    int cn=0;
    
    for(int i=0;i<N-1;i++){
        if(c[E[i].fi]!=c[E[i].se]){
            cn++;
            hin[E[i].fi]++;
            hin[E[i].se]++;
        }
    }
    
    if(cn==0){
        cout<<"YES\n";
        cout<<1<<"\n";
    }else{
        for(int i=0;i<N;i++){
            if(hin[i]==cn){
                cout<<"YES\n";
                cout<<i+1<<"\n";
                return 0;
            }
        }
        cout<<"NO\n";
    }
}