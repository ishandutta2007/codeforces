#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;
void solve();

#define mp make_pair
#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
const int mod=1000000007;
li binpow (li a, li n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return (binpow (a, n-1) * a) %mod;
    else {
        li b = binpow (a, n/2);
        return (b * b) %mod;
    }
}
li c(li n,li k){
    li res=1;
    for(int i=1;i<=k;++i){
        res*=n-i+1;
        res%=mod;
        res*=binpow(i,mod-2);
        res%=mod;
    }
    return res;
}
void solve() {
    li n,m,k;
    cin>>n>>m>>k;
    if(min(n,m)<2*k+1)
        cout<<"0";
    else{
        cout<<(c(n-1,2*k)*c(m-1,2*k)%mod);
    }

}