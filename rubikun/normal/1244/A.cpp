#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=200003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        int a,b,c,d,k;cin>>a>>b>>c>>d>>k;
        int x=(a+c-1)/c,y=(b+d-1)/d;
        if(x+y<=k) cout<<x<<" "<<y<<endl;
        else cout<<-1<<endl;
        T--;
    }
}