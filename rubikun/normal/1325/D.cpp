#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;
vector<pair<int,int>> G[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll a,b;cin>>a>>b;
    if(a>b||((a&1)!=(b&1))){
        cout<<-1<<endl;
        return 0;
    }
    if(a==b){
        if(a){
            cout<<1<<endl;
            cout<<a<<endl;
        }else{
            cout<<0<<endl;
        }
        return 0;
    }
    ll c=(b-a)/2;
    if((a&c)==0){
        cout<<2<<endl;
        cout<<c<<" "<<a+c<<endl;
    }else{
        cout<<3<<endl;
        cout<<c<<" "<<c<<" "<<a<<endl;
    }
}