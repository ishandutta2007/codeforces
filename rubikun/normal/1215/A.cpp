#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int a,b,c,d,n;cin>>a>>b>>c>>d>>n;
    if(c>d){
        swap(c,d);
        swap(a,b);
    }
    
    int n2=n;
    n2-=a*(c-1)+b*(d-1);
    cout<<max(0,n2)<<" ";
    
    if(a*c<n){
        n-=a*c;
        cout<<a+n/d<<endl;
    }else{
        cout<<n/c<<endl;
    }
    
}