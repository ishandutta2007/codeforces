#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string A,B;cin>>A>>B;
    int ans=0,cnt=0;
    for(int i=0;i<B.size();i++){
        if(A[i]!=B[i]) cnt++;
    }
    if(cnt%2==0) ans++;
    
    for(int i=B.size();i<A.size();i++){
        if(A[i-B.size()]!=A[i]) cnt++;
        if(cnt%2==0) ans++;
    }
    
    cout<<ans<<endl;
}