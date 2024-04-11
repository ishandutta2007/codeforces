#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, a;
int q;

ll query(ll t, ll k){
    if(k % 2 == 1) return (k+1)/2;
    if(t == 3 && k == 2) return 3;

    ll dif = (k-1)/2;
    if(dif == 0) return query(t-1, t-1) + 1;
    //cout << t-dif << " " << t - dif * 2 << "dif = " << dif << endl;
    return query(t-dif, k-dif*2) + dif;
}

int main(){
    ll x,y;
    scanf("%I64d%d",&n,&q);
    while(q--){
        scanf("%I64d", &a);
        printf("%I64d\n", query(n,a));
    }
}