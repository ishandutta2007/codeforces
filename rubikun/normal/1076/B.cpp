#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll N;cin>>N;
    if(N%2==0) cout<<N/2<<endl;
    else{
        for(int i=3;i<=100000;i++){
            if(N%i==0){
                cout<<1+(N-i)/2<<endl;
                break;
            }
            if(i==100000) cout<<1<<endl;
        }
    }
}