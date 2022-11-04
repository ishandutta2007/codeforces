#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
const int N = 5e5 + 1;

int t, n, a[N], lseg[N], rseg[N];
bool used[N], usedused[N];

struct node{
    int l, r;
    bool operator<(const node &b) const{
        return l < b.l;
    }
} seg[N];

vector<int> vec[N];
priority_queue<int, vector<int>, greater<int>> q;

bool chk(int k){
    memset(seg + 1, 0, sizeof(node) * n);
    for (int i = 0; i <= k; i++)
        vec[i].clear();
    memset(used + 1, 0, sizeof(bool) * n);
    int cnt = 0, i, j;
    for (i = 1; i <= n; i++){
        if(!a[i]){
            lseg[++cnt] = i;
            if(cnt == k)
                break;
        }
    }
    if(cnt < k)
        return false;
    cnt = 0;
    for (j = n; j > i; j--){
        if(!a[j]){
            rseg[++cnt] = j;
            if(cnt == k)
                break;
        }
    }
    if(cnt < k)
        return false;
    int cntm = 0;
    for (int p = i + 1; p < j; p++){
        if(a[p] && !used[a[p]]){
            used[a[p]] = true;
            cntm++;
        }
    }
    memset(usedused + 1, 0, sizeof(bool) * n);
    int kk = k;
    for (int p = i; p; p--){
        if(p == lseg[kk])
            kk--;
        if(a[p] && !used[a[p]] && !usedused[a[p]]){
            usedused[a[p]] = true;
            seg[a[p]].l = kk;
        }
    }
    kk = k;
    memset(usedused + 1, 0, sizeof(bool) * n);
    for (int p = j; p <= n; p++){
        if(p == rseg[kk])
            kk--;
        if(a[p] && !used[a[p]] && !usedused[a[p]]){
            usedused[a[p]] = true;
            seg[a[p]].r = kk;
        }
    }
    sort(seg + 1, seg + 1 + n);
    int now = 0;
    for (int i = 1; i <= n; i++)
        if(seg[i].l > now)
            now++;
    for (int i = 1; i <= n; i++){
        seg[i].l = min(seg[i].l, now);
        vec[seg[i].l].push_back(seg[i].r);
    }
    while(q.size())
        q.pop();
    for (int i = now; i; i--){
        for(int j : vec[i])
            q.push(j);
        q.pop();
    }
    for(int j : vec[0])
        q.push(j);
    int nownow = 0;
    while(q.size()){
        if(q.top() > nownow)
            nownow++;
        q.pop();
    }
    return now + nownow + cntm >= k;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int l = 0, r = n / 3;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(chk(mid))
                l = mid;
            else
                r = mid - 1;
        }
        printf("%d\n", l);
    }
    return 0;
}