#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
const LL MOD = 1e9+7;
int n,a[N];
LL bit[N];
void add(int pos,LL x){
    while(pos<N){
        (bit[pos]+=x)%=MOD; pos+=pos&-pos;
    }
}
LL sum(int pos){
    LL ans=0;
    while(pos){
        (ans+=bit[pos])%=MOD; pos-=pos&-pos;
    }
    return ans;
}
vector<int> v;
int id(int x){
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    LL ans=0;
    for(int i=1;i<=n;i++){
        ans=ans+1LL*i*(n+1-i)%MOD*a[i]%MOD;
        ans=ans%MOD;
    }
    //cout<<ans<<endl;
    for(int i=n;i>=1;i--){
        ans=ans + 1LL*i * (sum(v.size()) - sum(id(a[i]))) % MOD;
        ans=ans % MOD;
        add(id(a[i]), 1LL*(n+1-i)*a[i]%MOD);
    }
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;i++){
        ans=ans + 1LL*(n+1-i) * (sum(v.size()) - sum(id(a[i]))) % MOD;
        ans=ans % MOD;
        add(id(a[i]), 1LL*i*a[i]%MOD);
    }
    ans=(ans%MOD+MOD)%MOD;
    cout<<ans<<endl;
}
/*
x, y

a[x] < a[y]

a[x] > a[y]


x * (n+1-y) * a[y]
x * (n+1-y) * a[x]



*/