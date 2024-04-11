#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<59;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    int acnt0=0,acnt1=0,bcnt0=0,bcnt1=0;
    
    for(int i=0;i<N;i++){
        int a;cin>>a;
        if(a%2==0) acnt0++;
        else acnt1++;
    }
    
    for(int i=0;i<M;i++){
        int a;cin>>a;
        if(a%2==0) bcnt0++;
        else bcnt1++;
    }
    
    cout<<min(acnt0,bcnt1)+min(acnt1,bcnt0)<<endl;
}