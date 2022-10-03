#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    bool ok=true;
    for(int i=1;i<N;i++){
        if(S[i-1]>S[i]){
            cout<<"YES"<<endl;
            cout<<i<<" "<<i+1<<endl;
            ok=false;
        }
        if(!ok) break;
    }
    if(ok) cout<<"NO"<<endl;
    
    
    
}