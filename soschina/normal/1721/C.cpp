#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1, L = 20;

int t, n, lg2[N] = {-1}, a[N], b[N], st[N][L], ansmin[N], ansmax[N];

int query(int l, int r){
    if(r < l)
        return 0;
    int t = lg2[r - l + 1];
    return min(st[l][t], st[r - (1 << t) + 1][t]);
}

int main(){
    for (int i = 1; i < N; i++)
        lg2[i] = lg2[i - 1] + (i == (i & -i));
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        for (int i = 1; i < n; i++)
            st[i][0] = b[i] - a[i + 1];
        for (int j = 1; j < L; j++)
            for (int i = 1; i + (1 << j) <= n; i++)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        for (int i = 1; i <= n; i++){
            int l = 1, r = i;
            while(l < r){
                int mid = (l + r) >> 1;
                if(a[i] <= b[mid])
                    r = mid;
                else
                    l = mid + 1;
            }
            ansmin[i] = b[l] - a[i];
            l = i - 1, r = n - 1;
            while(l < r){
                int mid = (l + r + 1) >> 1;
                if(query(i, mid) >= 0)
                    l = mid;
                else
                    r = mid - 1;
            }
            ansmax[i] = b[l + 1] - a[i];
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", ansmin[i]);
        putchar('\n');
        for (int i = 1; i <= n; i++)
            printf("%d ", ansmax[i]);
        putchar('\n');
    }
    return 0;
}