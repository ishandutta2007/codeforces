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
        string a,b;cin>>a>>b;
        int x=int(a.size()),y=int(b.size());
        
        int c,d;
        for(int j=0;j<y;j++){
            if(b[y-1-j]=='1'){
                c=j;
                break;
            }
        }
        
        for(int j=c;j<x;j++){
            if(a[x-1-j]=='1'){
                d=j;
                break;
            }
        }
        
        cout<<d-c<<endl;
    }
}