#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=300005,INF=1<<30;
set<int> G[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> p(N),ok(N);
    for(int i=0;i<N;i++){
        cin>>p[i];
        p[i]--;
    }
    int s=p[N-1];
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].insert(b);
        if(b==s) ok[a]=1;
    }
    
    for(int i=N-2;i>=0;i--){
        if(!ok[p[i]]) continue;
        int now=i,see=p[i];
        while(now<N-1){
            if(G[see].find(p[now+1])==G[see].end()) break;
            swap(p[now],p[now+1]);
            now++;
        }
    }
    
    for(int i=0;i<N;i++){
        if(p[i]==s){
            cout<<N-1-i<<endl;
            return 0;
        }
    }
}