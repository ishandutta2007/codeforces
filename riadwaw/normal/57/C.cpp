#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long li;
typedef pair<li, li> pli;
typedef long double ld;
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
li sqr(li a){
    return a*a;
}
int p=1000000007;
li binpow(li a,li q){
    if(!q)
        return 1;
    if(q%2)
        return (a*binpow(a,q-1)%p);
    else
        return sqr(binpow(a,q/2))%p;
}
void solve(){
    int n;
    cin>>n;
    li res=1;
    li del=1;
    for(int i=1;i<n;++i){
        res=(res*(n+i))%p;
        del=(del*i)%p;
    }
    res*=binpow(del,p-2);
    res%=p;
    res*=2;
    res-=n;
    if(res<0)
        res+=p;
    cout<<res%p;
}