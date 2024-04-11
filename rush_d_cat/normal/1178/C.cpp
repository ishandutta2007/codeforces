#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL MOD = 998244353;

int n,m;

int main() {
    cin>>n>>m;
    LL res=1;
    for(int i=1;i<=n+m;i++)res=res*2%MOD;
    cout<<res<<endl;
}