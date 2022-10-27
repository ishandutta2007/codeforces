#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
const int N = 1000000+10;

int cnt;
struct Seg {
    int L, R, val, id, len;
    int pre, nxt;
    bool operator < (const Seg o) const {
        if (len == o.len)
            return L < o.L;

        return len > o.len;
    } 
} seg[N];

int n;
int a[N];

int main() {
    scanf("%d", &n);
    set<Seg> st;
    
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    int L = 1, R = 1;
    for (int i = 2; i <= n+1; i ++) {
        if (a[i] == a[i-1] && i <= n) {
            R ++;
        } else {
            Seg tmp; 
            tmp.L = L, tmp.R = R; tmp.val = a[L]; tmp.len = R-L+1;
            tmp.id = ++cnt; tmp.pre = cnt-1, tmp.nxt=cnt+1;
            st.insert(tmp); seg[cnt] = tmp;
            //printf("%d %d\n", L, R);
            L = i, R = i;
        }
    }
    seg[0].L=1, seg[0].R=0;
    seg[cnt+1].L=1, seg[cnt+1].R=0;
    
    int ans = 0;
    while (st.size()) {
        Seg tmp = *st.begin(); st.erase(st.begin()); 
        ans ++;

        //printf("%d %d\n", tmp.L, tmp.R);
        
        if (tmp.pre == 0 && tmp.nxt == cnt+1)
            break;

        Seg pre = seg[tmp.pre]; //printf("%d %d\n", pre.L, pre.R);
        Seg nxt = seg[tmp.nxt]; //printf("%d %d\n", nxt.L, nxt.R);
        
        st.erase(pre);
        st.erase(nxt);
        //printf("pre=%d nxt=%d\n", pre.val, nxt.val);
        if (pre.val == nxt.val) {
            st.erase(seg[nxt.nxt]);
            int t = pre.len + nxt.len;
            seg[pre.id].R = pre.R = nxt.R;
            seg[pre.id].len = pre.len = t;
            seg[pre.id].nxt = pre.nxt = nxt.nxt;
            seg[nxt.nxt].pre = pre.id;
            //printf("in: %d %d %d\n", pre.L, pre.R, pre.len);
            if (pre.id) st.insert(pre);
            if (nxt.nxt<=cnt) st.insert(seg[nxt.nxt]);

        } else {
            seg[pre.id].nxt = pre.nxt = tmp.nxt; 
            seg[nxt.id].pre = nxt.pre = tmp.pre;
            if (pre.id) st.insert(pre); 
            if (nxt.id<=cnt) st.insert(nxt);
        }

    
    }
    printf("%d\n", ans);
}