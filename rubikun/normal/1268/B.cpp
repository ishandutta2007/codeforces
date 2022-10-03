#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    ll cnt1=0,cnt2=0;
    
    for(int i=0;i<N;i++){
        ll a;cin>>a;
        if(i%2==0){
            cnt1+=(a+1)/2;
            cnt2+=a/2;
        }else{
            cnt1+=a/2;
            cnt2+=(a+1)/2;
        }
    }
    
    cout<<min(cnt1,cnt2)<<endl;
}