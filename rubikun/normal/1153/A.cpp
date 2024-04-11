#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,T;cin>>N>>T;
    int ti=INF,ans=-1;
    
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        if(T<=a){
            if(ti>a){
                ti=a;
                ans=i+1;
            }
        }else{
            if(ti>a+(T-a+b-1)/b*b){
                ti=a+(T-a+b-1)/b*b;
                ans=i+1;
            }
        }
    }
    
    cout<<ans<<endl;
}