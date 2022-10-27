#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

int n, k;
bool chk(int x) {
    bool ok = 1;
    while(x) {
        if (x%10!=4 && x%10!=7) ok=0;
        x /= 10;
    }
    return ok;
}

vector<LL> v;
void dfs(int dep,LL now) {
    if(now) v.push_back(now);
    if(dep==9) return;
    dfs(dep+1, now*10+4);
    dfs(dep+1, now*10+7);
}
LL fac[20];
int main() {
    cin >> n >> k;
    dfs(0,0);sort(v.begin(),v.end());
    //for(auto x: v) printf("%d\n", x);
    fac[0]=1;
    for(int i=1;i<=15;i++) {
        fac[i]=fac[i-1]*i;
    }

    int low=0, ans=0;

    if (n>=15) {
        low = n-14; n=14;
        ans = upper_bound(v.begin(),v.end(),low) - v.begin();
    } else {
        if(fac[n] < k) return !printf("-1\n");
    }

    bool vis[16]={0};
    for(int i=n;i>=1;i--) {
        int cnt = (k-1) / fac[i-1];
        //printf("fac = %d, cnt = %d\n", fac[i-1], cnt);
        int id = 0;
        for(int j=1;j<=n;j++) {
            if(vis[j]) continue;
            if(id==cnt) { 
                k -= cnt * fac[i-1];
                vis[j]=1;  //printf("j=%d\n", j);
                int pos = low + (n+1-i);
                int val = low + (j);
                //printf("pos=%d, val=%d\n", pos,val);
                if (chk(pos) && chk(val)) ans ++;
                break;
            }
            id ++;
        }
    }

    cout << ans << endl;
}