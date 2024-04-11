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
        int N;cin>>N;
        string S;cin>>S;
        string T;cin>>T;
        //int N=si(S);
        map<pair<char,char>,int> MA;
        for(int i=0;i<N;i++){
            char c=S[i],d=T[N-1-i];
            if(c>d) swap(c,d);
            MA[mp(c,d)]++;
        }
        
        int cn=0;
        for(auto a:MA){
            if(a.se&1){
                if(N&1){
                    if(a.fi.fi==a.fi.se) cn++;
                    else cn=INF;
                }else{
                    cn=INF;
                }
            }
        }
        
        if(cn<=1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}