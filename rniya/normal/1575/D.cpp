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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<61;

const int M=10,MM=25;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    if(si(S)==1){
        if(S[0]=='X'||S[0]=='_'||S[0]=='0') cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    vector<int> idx;
    int lim=1;
    for(int i=0;i<si(S);i++){
        lim*=10;
        if(S[i]=='X') idx.push_back(i);
    }
    
    int ans=0;
    for(int i=lim/10;i<lim;i++){
        if(i%MM) continue;
        string U=to_string(i);
        bool ok=true;
        for(int j=0;j<si(S);j++){
            if(S[j]!='_'&&S[j]!='X'){
                if(S[j]!=U[j]) ok=false;
            }
        }
        if(!ok) continue;
        for(int k=1;k<si(idx);k++) if(U[idx[0]]!=U[idx[k]]) ok=false;
        if(ok) ans++;
    }
    
    cout<<ans<<endl;
    
}