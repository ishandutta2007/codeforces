#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 1;

int t, n, k, a[N];
int id[N];

bool cmp(int x, int y){
    return a[x] < a[y];
}

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++){
            id[i] = i;
            scanf("%d", &a[i]);
        }
        sort(id + 1, id + 1 + n, cmp);
        int p = 1;
        while(k > 2){
            a[id[p]] = 1e9;
            p++;
            k--;
        }
        if(k == 2){
            a[id[p]] = 1e9;
            p++;
            k--;
            sort(id + 1, id + 1 + n, cmp);
            int ans = min(2 * a[id[1]], (int)1e9);
            a[id[1]] = 1e9;
            int maxpairmin = 0;
            for (int i = 1; i < n; i++)
                maxpairmin = max(maxpairmin, min(a[i], a[i + 1]));
            sort(id + 1, id + 1 + n, cmp);
            ans = max(ans, min(maxpairmin, 2 * a[id[1]]));
            printf("%d\n", ans);
        }
        else{
            int maxa = 0;
            for (int i = 1; i <= n; i++)
                maxa = max(maxa, a[i]);
            int ans = min(maxa, 2 * a[id[1]]);
            a[id[1]] = 1e9;
            int maxpairmin = 0;
            for (int i = 1; i < n; i++)
                maxpairmin = max(maxpairmin, min(a[i], a[i + 1]));
            sort(id + 1, id + 1 + n, cmp);
            ans = max(ans, min(maxpairmin, 2 * a[id[1]]));
            printf("%d\n", ans);
        }
    }
	return 0;
}