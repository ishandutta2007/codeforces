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
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        string S;cin>>S;
        bool f=false;
        for(char c:S) if(c=='1') f=true;
        if(!f){
            cout<<S<<"\n";
            continue;
        }
        
        while(M--){
            string T=S;
            for(int i=0;i<N;i++){
                if(T[i]=='0'){
                    int cnt=0;
                    if(i-1>=0&&S[i-1]=='1') cnt++;
                    if(i+1<N&&S[i+1]=='1') cnt++;
                    if(cnt==1){
                        T[i]='1';
                    }
                }
            }
            if(S==T) break;
            S=T;
        }
        
        cout<<S<<"\n";
    }
}