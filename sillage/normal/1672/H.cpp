#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int p[maxn];
int bt0[maxn], bt1[maxn];
char a[maxn];
int main(){
    int n, q;
    cin >> n >> q;
    scanf("%s", a + 1);
    memset(p, -1, sizeof(p));
    for (int i = 2; i <= n; i++) if (a[i] == a[i - 1]) {
        if (a[i] == '1') {
            for (int j = i; j <= n; j += j & (-j)) bt1[j]++;
            p[i] = 1;
        }else{
            for (int j = i; j <= n; j += j & (-j)) bt0[j]++;
            p[i] = 0;
        }
    }
    while (q--){
        int l, r;
        scanf("%d%d", &l, &r);
        int c0 = 0, c1 = 0;
        for (int i = r; i >= 1; i -= i & (-i)) c0 += bt0[i], c1 += bt1[i];
        for (int i = l; i >= 1; i -= i & (-i)) c0 -= bt0[i], c1 -= bt1[i];
        cout << max(c0, c1) + 1 << '\n'; 
    }

}