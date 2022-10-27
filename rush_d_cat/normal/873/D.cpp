#include <iostream>
using namespace std;
int n, k;
int cur, ans[100000+10];

void dfs(int L, int R) 
{
    if (k == 0 || R - L == 1) {
        for (int i = R - 1; i >= L; i --) 
            ans[i] = cur --;
        return;
    }
    if (k >= 2) {
        int mid = (L + R) / 2; k -= 2;
        dfs(L, mid); dfs(mid, R);
    }
}

int main() 
{
    cin >> n >> k; cur = n; 
    k --; dfs(0, n); 

    if (cur || k)
        printf("-1\n");
    else
        for (int i = 0; i < n; i ++) 
            printf("%d ", ans[i]);
}