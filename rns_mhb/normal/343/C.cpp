#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
#define M 100100
map<ll, bool>mp;
int n, m;
ll a[M], b[M];

ll len(ll lef, ll rig, ll now){
    if(lef>=now)return rig-now;
    if(now>=rig)return now-lef;
    return min(rig-now, now-lef)+rig-lef;
}

bool ok(ll step){
    int i, j, k;
    int cur=0;
    for(i=0; i<n; i++){
        for(k=cur; k<m; k++){
            if(len(b[cur], b[k], ll(a[i]))>step)break;
        }
        cur=k;
    }
    return cur==m;
}

int main(){
    //freopen("C3.in", "r", stdin);
    int i, j, k;
    int ans=1;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)scanf("%I64d", a+i), mp[a[i]]=1;
    for(i=0; i<m; i++){
        scanf("%I64d", b+i);
        if(!mp.count(b[i]))ans=0;
    }
    if(ans){
        puts("0");
        return 0;
    }

    ll mn=0, mx=20000000000ll;
    //puts("ABC");
    while(mn<mx-1){
        ll mid=(mn+mx)/2;
        if(ok(mid))mx=mid;
        else mn=mid;
        //puts("T");
    }
    printf("%I64d\n", mx);
    return 0;
}