#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,D,E;cin>>N>>D>>E;
    E*=5;
    int ans=N;
    for(int i=0;i*E<=N;i++){
        int a=N-i*E;
        ans=min(ans,a%D);
    }
    cout<<ans<<endl;
}