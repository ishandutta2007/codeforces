#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cout<<"?";
    
    for(int i=0;i<100;i++){
        cout<<" "<<i;
    }
    cout<<endl;
    
    int N;cin>>N;
    
    int ans=0;
    
    for(int i=7;i<14;i++){
        if(N&(1<<i)) ans+=(1<<i);
    }
    
    cout<<"?";
    
    for(int i=1;i<=100;i++){
        cout<<" "<<i*(1<<7);
    }
    cout<<endl;
    
    int M;cin>>M;
    
    
    for(int i=0;i<=6;i++){
        if(M&(1<<i)) ans+=(1<<i);
    }
    
    cout<<"! "<<ans<<endl;
}