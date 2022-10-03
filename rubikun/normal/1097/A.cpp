#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<59;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    vector<string> T(5);
    for(int i=0;i<5;i++) cin>>T[i];
    
    bool ok=false;
    
    for(int i=0;i<5;i++){
        if(S[0]==T[i][0]||S[1]==T[i][1]) ok=true;
    }
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}