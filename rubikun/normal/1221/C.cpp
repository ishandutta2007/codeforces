#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=105,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    for(int k=0;k<Q;k++){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        if(min(a,b)*3<=a+b+c) cout<<min(a,b)<<"\n";
        else{
            cout<<(a+b+c)/3<<"\n";
        }
    }
}