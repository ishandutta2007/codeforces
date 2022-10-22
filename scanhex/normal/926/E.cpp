#include <stdio.h>
const int n = 200001;
int a[n], lst[n], have[n];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%d",&a[i]);
    }
    have[0] = 1;
    lst[0] = -1;
    for (int i=1;i<n;i++){
        lst[i] = i - 1;
        have[i] = 1;
    }
    for (int i=1;i<n;i++){
        while (1 == 1){
         if (lst[i]!=-1 && a[i] == a[lst[i]]){
                have[lst[i]] = 0;
                lst[i] = lst[lst[i]];
                a[i] = a[i] + 1;
          } else {
             break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i<n; i++){
        if (have[i] == 1) ans++;
    }
    printf("%d", ans);
    printf("\n");
        for (int i = 0; i<n; i++){
        if (have[i] == 1) printf("%d ", a[i]);
    }
    return 0;
}