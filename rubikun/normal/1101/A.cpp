#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    for(int k=0;k<Q;k++){
        ll L,R,D;cin>>L>>R>>D;
        if(D<L) cout<<D<<endl;
        else cout<<((R/D)+1)*D<<endl;
    }
}