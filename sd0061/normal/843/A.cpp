#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n , a[N] , f[N] , o[N] , Rank[N] , b[N];

int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        f[i] = o[i] = i;
    }
    sort(o , o + n , [](int x , int y) {return a[x] < a[y];});
    for (int i = 0 ; i < n ; ++ i) {
        f[getf(i)] = getf(o[i]);
    }
    int sum = 0;
    for (int i = 0 ; i < n ; ++ i) {
        sum += (getf(i) == i);
        b[i] = getf(i);
    }
    sort(o , o + n , [](int x , int y) {return b[x] < b[y];});
    printf("%d\n" , sum);
    for (int i = 0 ; i < n ; ++ i) {
        int j = i;
        while (j < n && b[o[i]] == b[o[j]]) {
            ++ j;
        }
        printf("%d" , j - i);
        for (int k = i ; k < j ; ++ k)
            printf(" %d" , o[k] + 1);
        puts("");
        i = j - 1;
    }
}