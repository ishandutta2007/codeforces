#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=3005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        int a,b,c;cin>>a>>b>>c;
        if(a>b) swap(a,b);
        if(b>c) swap(b,c);
        if(a>b) swap(a,b);
        
        if(a+b<=c) cout<<a+b<<"\n";
        else cout<<(a+b+c)/2<<"\n";
        
        T--;
    }
}