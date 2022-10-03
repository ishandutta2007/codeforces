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
    
    int Q;cin>>Q;
    while(Q--){
        int x,y,a,b;cin>>x>>y>>a>>b;
        if((y-x)%(a+b)==0) cout<<(y-x)/(a+b)<<endl;
        else cout<<-1<<endl;
    }
}