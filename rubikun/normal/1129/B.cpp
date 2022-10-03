#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll K;cin>>K;
    cout<<2000<<endl;
    cout<<-1;
    K+=2000;
    for(int i=1;i<2000;i++){
        cout<<" ";
        if(K<=1000000){
            cout<<K;
            K=0;
        }else{
            cout<<1000000;
            K-=1000000;
        }
    }
    cout<<endl;
}