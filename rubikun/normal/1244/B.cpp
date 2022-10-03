#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=200003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        int N;string S;cin>>N>>S;
        int ans=N;
        for(int i=0;i<N;i++){
            if(S[i]=='1'){
                ans=max(ans,2*(i+1));
                ans=max(ans,2*(N-i));
            }
        }
        
        cout<<ans<<endl;
        T--;
    }
}