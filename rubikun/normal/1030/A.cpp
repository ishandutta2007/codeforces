#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2001,INF=1<<30;

int main(){
    
    /*std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());*/
    
    int N;cin>>N;
    bool ok=true;
    for(int i=0;i<N;i++){
        int a;cin>>a;
        if(a==1) ok=false;
    }
    if(ok) cout<<"Easy"<<endl;
    else cout<<"Hard"<<endl;
}