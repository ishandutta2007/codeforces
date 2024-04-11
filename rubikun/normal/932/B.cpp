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
    
    vector<vector<int>> cnt(1000005,vector<int>(10));
    vector<int> f(1000005);
    
    for(int i=1;i<=9;i++){
        cnt[i][i]++;
        f[i]=i;
    }
    
    for(int i=10;i<=1000000;i++){
        int ii=i;
        ll now=1;
        while(ii){
            if(ii%10) now*=ii%10;
            ii/=10;
        }
        int to=f[now];
        cnt[i][to]++;
        f[i]=to;
    }
    
    for(int j=1;j<=9;j++){
        for(int i=1;i<=1000000;i++){
            cnt[i][j]+=cnt[i-1][j];
        }
    }
    
    int Q;cin>>Q;
    while(Q--){
        int l,r,k;cin>>l>>r>>k;
        l--;
        cout<<cnt[r][k]-cnt[l][k]<<"\n";
    }
    
}