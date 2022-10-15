#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 233;
int value[maxn], n;

int c[maxn];

int lowbit(int x) {
    return x & (-x);
}
 
struct node{
    int x, y, z, id;
    bool operator <(const node &r) const{
        return x < r.x;
    }
}a[maxn], tmp[maxn];
 

bool cmp1(node a, node b) {
    return a.x < b.x;
}

bool cmp2(node a, node b) {
    return a.z < b.z;
}

void add(int x, int d){
    while(x < maxn){
        c[x] = max(c[x], d);
        x += lowbit(x);
    }
}
 
int query(int x){
    int ret = 0;
    while(x){
        ret = max(ret, c[x]);
        x -= lowbit(x);
    }
    return ret;
}
 
void clr(int x){
    while(x < maxn) {
        c[x] = 0;
        x += lowbit(x);
    }
}
 
int dp[maxn];
 
void cdq(int l, int r){
    if(l == r) return;
    int mid = l + r >> 1;
    cdq(l, mid);
    sort(a + mid + 1, a + r + 1, cmp1);
    int pl = l, pr = mid + 1, tot = l;
    while(pl <= mid && pr <= r){
        if(a[pl].x <= a[pr].x){
            add(a[pl].y, dp[a[pl].id]);
            tmp[tot++] = a[pl++];
        }
        else{
            dp[a[pr].id] = max(dp[a[pr].id], query(a[pr].y - 1) + 1);
            tmp[tot++] = a[pr++];
        }
    }
    while(pl <= mid) {
        add(a[pl].y, dp[a[pl].id]);
        tmp[tot++] = a[pl++];
    }
    while(pr <= r){
        dp[a[pr].id] = max(dp[a[pr].id], query(a[pr].y - 1) + 1);
        tmp[tot++] = a[pr++];
    }
    for(int i = l; i <= mid; i++) {
        clr(a[i].y);
    }

    sort(a + mid + 1, a + r + 1, cmp2);
    cdq(mid + 1, r);

    pl = l, pr = mid + 1, tot = l;
    while(pl <= mid && pr <= r){
        if(a[pl].x <= a[pr].x) tmp[tot++] = a[pl++];
        else tmp[tot++] = a[pr++];
    }
    while(pl <= mid) tmp[tot++] = a[pl++];
    while(pr <= r) tmp[tot++] = a[pr++];
    for(int i = l; i <= r; i++) a[i] = tmp[i];
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    int res = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i += 1){
        cin >> value[i];
        if(i - value[i] < 0) continue;   
        dp[i] = 1;
        a[++cnt] = node{i - value[i], value[i], i, i};
        //cerr << i - value[i] << " " << value[i] << " " << i << endl;
    }
    if(cnt == 0) {
        cout << "0\n";
        return 0;
    }
    cdq(1, cnt);
    for (int i = 1; i <= n; i += 1){
        //cerr << dp[i] << " \n"[i == n];
        res = max(res, dp[i]);
    }   
    cout << res << "\n";
    return 0;
}