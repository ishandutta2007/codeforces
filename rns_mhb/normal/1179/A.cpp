#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 100010

pii ans[N];
int a[N<<1];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int mx = *max_element(a + 1, a + n + 1);
    int st = 1, ed = n, m = 1;
    ans[0] = pii(a[1], a[2]);
    while(a[st] != mx) {
        ans[m] = pii(a[st], a[st+1]);
        int A = a[st], B = a[st+1];
        if(A < B) swap(A, B);
        a[st+1] = A, a[ed+1] = B;
        st ++, ed ++, m ++;
    }
    m --;
    while(q --) {
        long long x;
        scanf("%I64d", &x);;
        if(x <= m) printf("%d %d\n", ans[x].first, ans[x].second);
        else printf("%d %d\n", mx, a[st+(x-m-1)%(n-1)+1]);
    }
}