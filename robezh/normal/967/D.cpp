#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int MAXN = (int)3e5 + 500;

int n, x1, x2;
P c[MAXN];

int main() {
    scanf("%d%d%d", &n, &x1, &x2);
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i].first);
        c[i].second = i;
    }
    sort(c, c+n);

    for(int swapped = 0; swapped < 2; swapped++){
        if(swapped){int tmpx = x1; x1 = x2, x2 = tmpx;}
        for(int i = 0; i < n; i++){
            int nxt = (x1 + c[i].first-1) / c[i].first;
            if(i + nxt >= n) continue;
            int nxt2 = (x2 + c[i+nxt].first-1) / c[i+nxt].first;
            if(i + nxt + nxt2 > n) continue;

            vector<int> v1, v2;
            for(int j = i; j < i + nxt; j++)
                v1.push_back(c[j].second+1);
            printf("\n");
            for(int j = i+nxt; j < i+nxt+nxt2; j++)
                v2.push_back(c[j].second+1);

            printf("Yes\n");
            if(swapped) swap(v1,v2);
            printf("%d %d\n", v1.size(), v2.size());
            for(int x : v1) printf("%d ", x);
            printf("\n");
            for(int x : v2) printf("%d ", x);

            return 0;
        }
    }
    printf("No");

    return 0;
}