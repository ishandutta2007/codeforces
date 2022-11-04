#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
const int N = 1e5 + 1, L = 31;
typedef pair<int, int> duo;

int t, n, a[N], b[N];

int reorder(int l, int r, int d){
    int p = l, i, j;
    for (i = l; i <= r; i++)
        if((a[i] >> d) & 1){
            p = max(p, i);
            while(p <= r && ((a[p] >> d) & 1))
                p++;
            if(p > r)
                break;
            swap(a[i], a[p]);
        }
    p = l;
    for (j = l; j <= r; j++)
        if((b[j] >> d) & 1 ^ 1){
            p = max(p, j);
            while(p <= r && ((b[p] >> d) & 1 ^ 1))
                p++;
            if(p > r)
                break;
            swap(b[j], b[p]);
        }
    return i == j ? i : -1;
}

vector<duo> vec[L];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        vec[L - 1].clear();
        vec[L - 1].push_back(duo(1, n));
        for (int i = L - 2; i >= 0; i--){
            vec[i].clear();
            bool flag = true;
            for(duo pr : vec[i + 1]){
                int p = reorder(pr.first, pr.second, i);
                if(p != -1){
                    if(pr.first < p)
                        vec[i].push_back(duo(pr.first, p - 1));
                    if(p <= pr.second)
                        vec[i].push_back(duo(p, pr.second));
                }
                else
                    flag = false;
            }
            if(!flag)
                vec[i] = vec[i + 1];
        }
        int ans = (1 << 30) - 1;
        for (int i = 1; i <= n; i++)
            ans &= a[i] ^ b[i];
        printf("%d\n", ans);
    }
    return 0;
}