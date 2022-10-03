#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        ll S,A,B,C;cin>>S>>A>>B>>C;
        ll can=S/C;
        cout<<(can/A)*(A+B)+can%A<<endl;
        
        T--;
    }
    
    
}