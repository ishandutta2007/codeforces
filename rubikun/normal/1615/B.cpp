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

int rui[20][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    for(int t=0;t<20;t++){
        for(int i=1;i<=200000;i++){
            rui[t][i]=rui[t][i-1];
            if(i&(1<<t)) rui[t][i]++;
        }
    }
    
    int Q;cin>>Q;
    while(Q--){
        int l,r;cin>>l>>r;l--;
        int ma=0;
        for(int t=0;t<20;t++) chmax(ma,rui[t][r]-rui[t][l]);
        cout<<(r-l)-ma<<"\n";
    }
}