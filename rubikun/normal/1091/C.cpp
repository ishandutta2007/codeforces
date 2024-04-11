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
    
    ll N;cin>>N;
    set<ll> SE;
    
    for(ll i=1;i*i<=N;i++){
        if(N%i==0){
            ll sum=N/i,haba=i;
            SE.insert(sum*(sum-1)/2*haba+sum);
            
            swap(sum,haba);
            SE.insert(sum*(sum-1)/2*haba+sum);
        }
    }
    
    for(ll a:SE) cout<<a<<" ";
    cout<<endl;
}