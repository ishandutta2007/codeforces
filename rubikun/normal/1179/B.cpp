#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18;
const ll INF=1LL<<40;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    
    for(int i=1;i<=N/2;i++){
        for(int j=1;j<=M;j++){
            cout<<i<<" "<<j<<"\n";
            cout<<N+1-i<<" "<<M+1-j<<"\n";
        }
    }
    if(N%2){
        for(int j=1;j<=M/2;j++){
            cout<<(N+1)/2<<" "<<j<<"\n";
            cout<<(N+1)/2<<" "<<M+1-j<<"\n";
        }
        if(M%2) cout<<(N+1)/2<<" "<<(M+1)/2<<"\n";
    }
}