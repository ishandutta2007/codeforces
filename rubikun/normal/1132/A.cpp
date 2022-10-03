#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=200001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(c>0){
        if(a>0&&d>0&&a==d) cout<<1<<endl;
        else cout<<0<<endl;
    }else{
        if(a==d) cout<<1<<endl;
        else cout<<0<<endl;
    }
}