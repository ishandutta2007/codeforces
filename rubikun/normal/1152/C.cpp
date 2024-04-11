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
    
    ll A,B;cin>>A>>B;
    if(A>B) swap(A,B);
    ll diff=B-A;
    
    if(A<=diff){
        vector<ll> p;
        for(ll i=1;i*i<=diff;i++){
            if(diff%i==0){
                p.push_back(i);
                if(i*i!=diff) p.push_back(diff/i);
            }
        }
        sort(all(p));
        
        cout<<*(lower_bound(all(p),A))-A<<endl;
    }else{
        if(diff==0) cout<<0<<endl;
        else cout<<(A+diff-1)/diff*diff-A<<endl;
    }
}