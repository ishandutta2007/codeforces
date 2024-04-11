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
    
    int N,M;cin>>N>>M;
    string S,T;cin>>S>>T;
    int id=-1;
    for(int i=0;i<N;i++) if(S[i]=='*') id=i;
    if(id==-1){
        if(S==T) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else{
        if(si(S)>si(T)+1) cout<<"NO"<<endl;
        else{
            bool ok=true;
            for(int i=0;i<id;i++) if(S[i]!=T[i]) ok=false;
            id=si(S)-1-id;
            reverse(all(S));
            reverse(all(T));
            
            for(int i=0;i<id;i++) if(S[i]!=T[i]) ok=false;
            
            if(ok) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}