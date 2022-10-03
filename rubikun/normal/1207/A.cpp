#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int i=0;i<T;i++){
        int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
        int ans=0;
        for(int j=0;j<=50;j++){
            for(int k=0;k<=50;k++){
                if(j*2+k*2>a) continue;
                if(j>b||k>c) continue;
                ans=max(ans,j*d+k*e);
            }
        }
        cout<<ans<<endl;
    }
}