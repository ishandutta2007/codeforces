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
    
    int N;cin>>N;
    
    vector<pair<int,int>> S;
    
    vector<string> D(N);
    
    for(int i=0;i<N;i++){
        string T;cin>>T;
        D[i]=T;
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int x;cin>>x;
            x--;
            S.push_back(mp(x,i));
        }
    }
    
    sort(all(S));
    
    vector<char> ans(2000005,'a');
    
    int seen=-1;
    
    for(int i=0;i<si(S);i++){
        if(S[i].fi+si(D[S[i].se])-1<=seen) continue;
        int now=max(S[i].fi,seen+1);
        while(now<=S[i].fi+si(D[S[i].se])-1){
            ans[now]=D[S[i].se][now-S[i].fi];
            now++;
        }
        seen=now-1;
    }
    
    for(int i=0;i<=seen;i++) cout<<ans[i];
    
    cout<<endl;
    
    
}