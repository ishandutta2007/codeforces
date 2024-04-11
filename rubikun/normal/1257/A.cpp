#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000003,MAX=300003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        int N,X,A,B;cin>>N>>X>>A>>B;
        cout<<min(abs(A-B)+X,N-1)<<endl;
        
        T--;
    }
    
}