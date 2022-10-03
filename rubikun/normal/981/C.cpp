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

vector<int> G[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    if(N==2){
        cout<<"Yes"<<endl;
        cout<<1<<endl;
        cout<<1<<" "<<2<<endl;
        return 0;
    }
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    vector<int> leaf,root;
    
    for(int i=0;i<N;i++){
        if(si(G[i])==1) leaf.push_back(i);
        if(si(G[i])>=3) root.push_back(i);
    }
    
    if(si(root)>=2){
        cout<<"No"<<endl;
    }else if(si(root)==1){
        cout<<"Yes"<<endl;
        cout<<si(leaf)<<endl;
        int ro=root[0];
        for(int u:leaf) cout<<ro+1<<" "<<u+1<<"\n";
    }else{
        cout<<"Yes"<<endl;
        cout<<1<<endl;
        cout<<leaf[0]+1<<" "<<leaf[1]+1<<"\n";
    }
}