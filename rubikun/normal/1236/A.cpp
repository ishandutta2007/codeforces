#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        int a,b,c;cin>>a>>b>>c;
        int ans=0;
        for(int i=0;i<=100;i++){
            if(i==0){
                for(int j=1;j<=100;j++){
                    if(j<=b&&j*2<=c) ans=max(ans,j*3);
                }
            }else{
                if(i<=a&&i*2<=b) ans=max(ans,i*3);
                for(int j=1;j<=100;j++){
                    if(i<=a&&i*2+j<=b&&j*2<=c) ans=max(ans,i*3+j*3);
                }
            }
        }
        cout<<ans<<endl;
        T--;
    }
}