#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,A,B;cin>>N>>A>>B;
        ll need=(N+1)/2;
        ll take=0;
        if(need%A==0){
            take=(need/A-1)*(A+B)+A;
        }else{
            take=need/A*(A+B)+need%A;
        }
        if(take-need>=N-need) cout<<take<<endl;
        else cout<<N<<endl;
    }
}