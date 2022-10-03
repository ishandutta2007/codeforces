#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S,T;cin>>S>>T;
    string U="aeiou";
    if(si(S)!=si(T)){
        cout<<"No"<<endl;
    }else{
        bool ok=true;
        
        for(int i=0;i<si(S);i++){
            int cnt=0;
            for(int j=0;j<5;j++){
                if(S[i]==U[j]) cnt++;
                if(T[i]==U[j]) cnt++;
            }
            if(cnt==1) ok=false;
        }
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}