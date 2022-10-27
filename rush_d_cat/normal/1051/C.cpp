#include <iostream>
using namespace std;
const int N = 102;
int n,a[N],cnt[N],A[N];
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        cnt[a[i]] ++;
    }
    int one = 0;
    for(int i=1;i<=100;i++) {
        if (cnt[i]==1) one ++;
    }

    int tmp = 0;
    for(int i=1;i<=100;i++) {
        if(cnt[i]==1) {
            tmp ++; if (tmp<=one/2) A[i] ++;
        }
    }

    if(one%2==0) {
        printf("YES\n");
        for(int i=1;i<=n;i++) {
            if((A[a[i]]--) >= 1) {
                printf("A"); 
            } else {
                printf("B");
            }
        }
        printf("\n");
    } else {
        bool ok = 0;
        for(int i=1;i<=100;i++) {
            if(cnt[i]>=3) {
                ok = 1; A[i] = 1; break;
            }
        }
        if (ok == 0) return !printf("NO\n");
        printf("YES\n");
        for(int i=1;i<=n;i++) {
            if((A[a[i]]--) >= 1) {
                printf("A"); 
            } else {
                printf("B");
            }
        }
        printf("\n");        
    }
}