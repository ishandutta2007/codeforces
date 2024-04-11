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
const int mod=1000000007,MAX=2005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    map<string,string> MA;
    
    for(int i=1989;i<=113098;i++){
        string S=to_string(i);
        for(int j=si(S)-1;j>=0;j--){
            string T=S.substr(j);
            if(MA.count(T)) continue;
            MA[T]=S;
            //cout<<i<<" "<<T<<endl;
            break;
        }
    }
    int Q;cin>>Q;
    
    while(Q--){
        string S;cin>>S;
        S=S.substr(4);
        if(MA.count(S)){
            cout<<MA[S]<<"\n";
            continue;
        }
        
        string T;
        for(int i=0;i<si(S)-4;i++) T+='1';
        T+="3099";
        
        if(S>=T) cout<<S<<"\n";
        else cout<<'1'<<S<<"\n";
    }
}