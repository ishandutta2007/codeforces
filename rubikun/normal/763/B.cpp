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
    cout<<"YES\n";
    for(int i=0;i<N;i++){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        x1=abs(x1);y1=abs(y1);
        int res=0;
        if(x1&1) res++;
        if(y1&1) res+=2;
        cout<<res+1<<"\n";
    }
}