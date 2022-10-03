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
const int mod=998244353,MAX=200005,INF=1<<28;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    string T=S;
    sort(all(T));
    
    bool ok=true;
    if(S!=T) ok=false;
    vector<int> cnt(3);
    
    for(int i=0;i<si(S);i++){
        cnt[int(S[i]-'a')]++;
    }
    
    if(cnt[0]==0) ok=false;
    if(cnt[1]==0) ok=false;
    if(cnt[2]==0) ok=false;
    
    if(!(cnt[0]==cnt[2]||cnt[1]==cnt[2])) ok=false;
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}