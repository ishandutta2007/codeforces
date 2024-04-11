#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int q;
    scanf("%d", &q);
    for(int c = 0; c < q; c++){
        int n, r;
        scanf("%d %d", &n, &r);
        int x[100002];
        for(int i = 0; i < n; i++){
            scanf("%d", &x[i]);
        }
        queue<int> que;
        sort(x, x + n);
        x[n] = 100000000;
        int y[100002];
        int j = 0;
        int m = n;
        for(int i = 0; i < n; i++){
            y[j] = x[i];
            while(x[i] == x[i + 1]){
                i++;
                m--;
            }
            j++;
        }
        for(int i = 0; i < m; i++){
            int p = (y[i] + r - 1) / r;
            if(p >= m - i - 1){
                printf("%d\n", min(p, m - i));
                break;
            }
        }
    }
}