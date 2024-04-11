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
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        reverse(all(S));
        if(S[0]=='A'){
            cout<<"NO\n";
        }else{
            string T;
            for(char c:S){
                if(c=='B') T+=c;
                else{
                    if(si(T)&&T.back()=='B') T.pop_back();
                    else T+=c;
                }
            }
            
            bool f=true;
            for(char c:T) f&=(c=='A');
            
            if(f) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}