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
    
    ll N;cin>>N;
    string S;cin>>S;
    
    ll ans=(N-1)*(N)/2;
    
    for(int i=0;i<N;i++){
        int now=i-1;
        while(now>=0&&S[now]!=S[i]){
            now--;
            ans--;
        }
        now=i+1;
        while(now<N&&S[now]!=S[i]){
            now++;
            ans--;
        }
        if(i&&S[i-1]!=S[i]) ans++;
    }
    
    cout<<ans<<endl;
}