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
const int mod=998244353,MAX=32768;
const ll INF=1LL<<60;

ll dis[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    for(int i=1;i<MAX;i++) dis[i]=INF;
    
    for(ll t=1;t<=30;t++){
        for(int i=0;i<MAX;i++){
            if(dis[(i+1)%MAX]<t) chmin(dis[i],t);
            if(dis[(i*2)%MAX]<t) chmin(dis[i],t);
        }
    }
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        int x;cin>>x;
        cout<<dis[x]<<" ";
    }
    cout<<"\n";
}