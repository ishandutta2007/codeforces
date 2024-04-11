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
const int mod=998244353,MAX=200005;
const ll INF=1LL<<61;

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        bool ans=false;
        vector<string> T(N);
        set<string> SE;
        for(int i=0;i<N;i++){
            string S;cin>>S;
            T[i]=S;
            if(si(S)==1) ans=true;
            else if(si(S)==2){
                if(S[0]==S[1]) ans=true;
                //else SE.insert(S);
            }else{
                if(S[0]==S[2]) ans=true;
                //else SE.insert(S);
            }
        }
        if(ans){
            cout<<"YES\n";
            continue;
        }
        
        for(int i=si(T)-1;i>=0;i--){
            string x=T[i];
            if(si(x)==2){
                char a=x[0],b=x[1];
                string A;A+=b;A+=a;
                if(SE.count(A)) ans=true;
                for(char c='a';c<='z';c++){
                    string B;B+=c;B+=b;B+=a;
                    if(SE.count(B)) ans=true;
                }
            }else{
                char a=x[0],b=x[1],c=x[2];
                if(a!=b&&a!=c&&b!=c){
                    string A;A+=b;A+=a;
                    if(SE.count(A)) ans=true;
                    string B;B+=c;B+=b;B+=a;
                    if(SE.count(B)) ans=true;
                }else if(a==b){
                    string A;A+=c;A+=b;A+=a;
                    if(SE.count(A)) ans=true;
                }else{
                    string A;A+=b;A+=a;
                    if(SE.count(A)) ans=true;
                    string B;B+=c;B+=b;B+=a;
                    if(SE.count(B)) ans=true;
                }
            }
            SE.insert(x);
        }
        
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}