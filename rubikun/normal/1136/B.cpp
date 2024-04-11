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
    
    ll N,K;cin>>N>>K;
    
    if(K==1||K==N){
        cout<<6+(N-2)*3<<endl;
    }else{
        int ans1=0,ans2=0;
        ans1=6+(K-2)*3;
        ans1+=(K-1);
        ans1+=(N-K)*3;
        
        K=N+1-K;
        
        ans2=6+(K-2)*3;
        ans2+=(K-1);
        ans2+=(N-K)*3;
        
        cout<<min(ans1,ans2)<<endl;
    }
}