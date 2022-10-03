#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000003;
const ll INF=1LL<<60;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    int wait=3;
    bool ok=true;
    
    for(int i=0;i<N;i++){
        int a;cin>>a;
        if(wait==a) ok=false;
        
        wait=6-a-wait;
    }
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}