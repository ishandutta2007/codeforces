#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003;
const ll INF=1LL<<50;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    string S,ans;
    for(int i=0;i<(N-K)/2;i++) S+='1';
    S+='0';
    while(ans.size()<=N) ans+=S;
    cout<<ans.substr(0,N)<<endl;
}