#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
typedef long long LL;
set<LL> st;

int n;
void solve(int x){
    LL len=(n-1)/x + 1;
    LL las=1+(n-1)/x * x;
    st.insert((1+las)*len/2);    
}
int main(){
    cin>>n;
    for(int x=1;x*x<=n;x++) {
        if(n%x==0){
            solve(x);
            if(x*x!=n) solve(n/x); 
        }
    }
    for(auto x: st) 
        printf("%lld ", x);
}