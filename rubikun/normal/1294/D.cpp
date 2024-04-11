#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q,X;cin>>Q>>X;
    vector<int> cnt(X),state(X+Q);
    int now=0;
    
    for(int i=0;i<Q;i++){
        int a;cin>>a;
        a%=X;
        if(a+cnt[a]*X<state.size()) state[a+cnt[a]*X]=1;
        cnt[a]++;
        
        while(state[now]==1) now++;
        
        cout<<now<<"\n";
    }
}