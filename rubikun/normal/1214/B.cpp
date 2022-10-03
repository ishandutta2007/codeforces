#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int B,G,N;cin>>B>>G>>N;
    int ans=0;
    for(int i=0;i<=B;i++){
        int j=N-i;
        if(0<=j&&j<=G) ans++;
    }
    
    cout<<ans<<endl;
}