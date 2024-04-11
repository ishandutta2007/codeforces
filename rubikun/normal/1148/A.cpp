#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000003;
const ll INF=1LL<<60;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll A,B,C;cin>>A>>B>>C;
    if(A<B) cout<<C*2+A+A+1<<endl;
    else if(A==B) cout<<C*2+A+B<<endl;
    else cout<<C*2+B+B+1<<endl;
    
}