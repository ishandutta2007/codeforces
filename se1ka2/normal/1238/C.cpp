#include <iostream>
using namespace std;

int main()
{
    int q;
    scanf("%d", &q);
    for(int c = 0; c < q; c++){
        int h, n;
        scanf("%d %d", &h, &n);
        int p[200004];
        for(int i = 0; i < n; i++){
            scanf("%d", &p[i]);
        }
        p[n] = 0;
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(p[i + 1] != p[i] - 1) ans++;
            else i++;
        }
        printf("%d\n", ans);
    }
}