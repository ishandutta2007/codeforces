#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    
    for(int i=0;i<T;i++){
        int N;cin>>N;
        int b=N%45451,c=N/45451;
        
        cout<<"133";
        for(int j=0;j<b;j++){
            cout<<'7';
        }
        for(int j=0;j<300;j++){
            cout<<'3';
        }
        for(int j=0;j<c;j++){
            cout<<'7';
        }
        
        cout<<endl;
    }
}