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
const int mod=1000000007,MAX=5005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int cnt=0;
        while(1){
            bool ok=false;
            for(int i=0;i+1<si(S);){
                if(S[i]!=S[i+1]){
                    ok=true;
                    cnt++;
                    S[i]='2';
                    S[i+1]='2';
                    i+=2;
                }else i++;
            }
            if(!ok) break;
            
            string T;
            for(int i=0;i<si(S);i++){
                if(S[i]!='2') T+=S[i];
            }
            
            S=T;
        }
        
        if(cnt&1) cout<<"DA\n";
        else cout<<"NET\n";
    }
}