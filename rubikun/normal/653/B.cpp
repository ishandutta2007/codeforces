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
const int mod=998244353,MAX=3005,INF=1<<30;

map<string,string> MA;
int N;

int ans=0;

void DFS(string S){
    if(si(S)==N){
        while(si(S)>1){
            string T=S.substr(0,2);
            if(!MA.count(T)) return;
            S=MA[T]+S.substr(2);
        }
        if(S[0]=='a') ans++;
        return;
    }
    for(char c='a';c<='f';c++){
        S+=c;
        DFS(S);
        S.pop_back();
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    int Q;cin>>Q;
    while(Q--){
        string A,B;cin>>A>>B;
        MA[A]=B;
    }
    DFS("");
    cout<<ans<<endl;
}