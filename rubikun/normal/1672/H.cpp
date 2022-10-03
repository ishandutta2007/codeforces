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

int rui[2][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q;cin>>N>>Q;
    string S;cin>>S;
    for(int i=0;i+1<N;i++){
        if(S[i]=='0'&&S[i+1]=='0') rui[0][i+1]++;
        if(S[i]=='1'&&S[i+1]=='1') rui[1][i+1]++;
    }
    for(int t=0;t<2;t++){
        for(int i=1;i<=N;i++){
            rui[t][i]+=rui[t][i-1];
        }
    }
    while(Q--){
        int l,r;cin>>l>>r;l--;
        if(r-l==1) cout<<1<<"\n";
        else{
            int a=max(rui[0][r-1]-rui[0][l],rui[1][r-1]-rui[1][l]);
            cout<<a+1<<"\n";
        }
    }
}