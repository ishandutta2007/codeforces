#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool valid(ll x){
    ll sum=0;
    ll y= x;
    while(y) sum+=y%10, y/=10;
    return __gcd(x, sum) > 1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        while(!valid(n))n++;
        cout<<n<<endl;
    }
}