#include <iostream>
#include <map>

using namespace std;
typedef long long LL;
int n,k,b;
int get(LL x){
    if(x<k) return x;
    int ans=0;
    while(x){
        ans += x%k;
        x /= k;
    }
    return get(ans);
}
map<int,int> mp;
map<LL,int> cnt;
// b + (d-1)*k

int main() {
    /*
    k=10;
    for(n=0;n<=1000;n++){
        if(get(n)==0)
            printf("%d\n", n);
    }
    */
    cin>>k>>b>>n;
    LL bu = 0;
    LL sum = 0, ssum = 0, ans = 0; mp[0] ++; cnt[0] ++;
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        sum += x; ssum += x;
        sum %= (k-1);
        int need = ((sum - b) % (k - 1) + (k-1)) % (k-1);
        ans += mp[need];
        if(b == k-1) {
            ans -= cnt[ssum];
        }
        if (b == 0) bu += cnt[ssum];
        //printf("need=%d, dt=%d, sum=%d\n", need,mp[need],sum);
        mp[sum] ++; cnt[ssum] ++;
    }
    if(b)
        cout << ans << endl;
    else
        cout << bu << endl;
}