#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 51;

int t, n, m, a[N], b[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", &b[i]);
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + m);
        if(a[n] >= b[m])
            puts("Alice");
        else{
            bool plyr = 0;
            int i = 1, j = 1;
            while(plyr == 0 ? (i <= n) : (j <= m)){
                if(plyr == 0){
                    while(j <= m && a[i] >= b[j])
                        j++;
                    i++;
                }else{
                    while(i <= n && a[i] <= b[j])
                        i++;
                    j++;
                }
                plyr ^= 1;
            }
            puts(plyr ? "Alice" : "Bob");
        }
        if(a[n] <= b[m])
            puts("Bob");
        else{
            bool plyr = 1;
            int i = 1, j = 1;
            while(plyr == 0 ? (i <= n) : (j <= m)){
                if(plyr == 0){
                    while(j <= m && a[i] >= b[j])
                        j++;
                    i++;
                }else{
                    while(i <= n && a[i] <= b[j])
                        i++;
                    j++;
                }
                plyr ^= 1;
            }
            puts(plyr ? "Alice" : "Bob");
        }
    }
    return 0;
}