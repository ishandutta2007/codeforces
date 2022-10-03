#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000003,MAX=300003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        int X,Y;cin>>X>>Y;
        if(X==1){
            if(Y==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else if(X==2||X==3){
            if(Y<=3) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else cout<<"YES"<<endl;
        
        T--;
    }
    
}