#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    while(N){
        ll X,Y;cin>>X>>Y;
        if((2*Y-X)%3==0&&(2*Y-X)/3>=0&&(2*X-Y)%3==0&&(2*X-Y)/3>=0) cout<<"YES\n";
        else cout<<"NO\n";
        
        N--;
    }
}