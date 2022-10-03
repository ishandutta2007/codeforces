#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    while(Q){
        int N;cin>>N;
        if(N<=3){
            cout<<4-N<<endl;
        }else if(N%2==0){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
        
        Q--;
    }
}