#include <stdio.h>
int maxn=10001;
long long cubes[10001];

int isCube(long long x) {
    int mindex=1, maxdex=maxn-1;
    while (mindex<=maxdex) {
        int mid=(mindex+maxdex)/2;
        if (cubes[mid]==x) return 1;
        if (cubes[mid]>x) maxdex=mid-1;
        else mindex=mid+1;
    }
    return 0;
}

int main() {
    for (long long i=0; i<maxn; i++)
        cubes[i]=i*(long long)i*i;

    long long T; 
    scanf("%lld", &T);
    for (int tt=0; tt<T; tt++) {
        long long x;
        scanf("%lld", &x);
        int found=0;
        for (long long toTry=1; toTry<maxn; toTry++) {
            if (cubes[toTry]<x && isCube(x-toTry*toTry*toTry)) {
                printf("YES\n");
                found=1;
                break;
            }
        }
        if (!found) {
            printf("NO\n");
        }
   }
   return 0;
}