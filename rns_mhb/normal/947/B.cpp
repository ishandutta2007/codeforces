#include <bits/stdc++.h>
using namespace std;

#define N 200005

typedef long long ll;

int n;
ll v[N], t[N], s[N];
ll ans[N];
int vis[N];

int main() {
   // freopen("sample.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%I64d", &v[i]);
    for (int i = 1; i <= n; i ++) {
        scanf("%I64d", &t[i]);
        s[i] = s[i-1] + t[i];
    }
    for (int i = 1; i <= n; i ++) {
        if (v[i] <= t[i]) {
            ans[i] += v[i];
            continue;
        }
        int st = i, en = n + 1;
        while (st < en) {
            int mid = st + en >> 1;
            if (mid == n + 1 || (mid != n + 1 && s[mid] - s[i-1] > v[i])) en = mid;
            else st = mid + 1;
        }
        st --;
//        cout<<i<<st<<endl;
        if (s[st] - s[i-1] == v[i]) vis[st] ++, vis[i-1] --;
        else {
            vis[st] ++, vis[i-1] --;
            ans[st+1] += v[i] - s[st] + s[i-1];
//            if (i == 3) cout<<ans[3];
//            cout<<i<<st<<endl;
        }
//        cout<<i<<ans[3]<<endl;
//        cout<<i<<v[i]<<endl;
    }
    for (int i = n; i >= 1; i --) vis[i-1] = vis[i-1] + vis[i];
//    for (int i = 1; i <= n; i ++) cout<<ans[i];cout<<endl;
    for (int i = 1; i <= n; i ++) ans[i] += vis[i] * t[i];
    for (int i = 1; i <= n; i ++) printf("%I64d ", ans[i]);
}