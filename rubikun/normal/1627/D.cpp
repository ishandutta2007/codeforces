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
const int mod=998244353,MAX=1000005,INF=1<<30;
bool aru[MAX];

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        int x;cin>>x;aru[x]=true;
    }
    for(int t=333333;t>=1;t--){
        if(aru[t]) continue;
        ll g=0;
        int la=0;
        for(int i=2*t;i<=1000000;i+=t){
            if(aru[i]){
                g=gcd(g,(i-la)/t);
                la=i;
            }
            if(g==1) break;
        }
        if(g==1) aru[t]=true;
    }
    int ans=0;
    for(int i=1;i<=1000000;i++) ans+=aru[i];
    
    cout<<ans-N<<endl;
}