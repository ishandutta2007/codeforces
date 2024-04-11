#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int i=0;i<T;i++){
        int a,b,c;cin>>a>>b>>c;
        if(c%3==0) cout<<a<<endl;
        else if(c%3==1) cout<<b<<endl;
        else cout<<(a^b)<<endl;
    }
}