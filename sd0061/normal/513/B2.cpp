#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , a[N];
LL m;
void work() {
    int i , j , k;
    cin >> n >> m;
    -- m;
    int l = 0 , r = n - 1;
    for (i = 1 ; i < n ; ++ i) {
        if ((~m >> (n - i - 1)) & 1)
            a[l ++] = i;
        else
            a[r --] = i;
    }
    a[l ++] = n;
    for (i = 0 ; i < n ; ++ i)
        printf("%d " , a[i]);
    puts("");
}

int main() {
//    freopen("1" , "r" , stdin);
    work();
    return 0;
}
/*
1 2 3 4 5 
1 2 3 5 4 
1 2 4 5 3 
1 2 5 4 3 
1 3 4 5 2 
1 3 5 4 2 
1 4 5 3 2 
1 5 4 3 2 
2 3 4 5 1 
2 3 5 4 1 
2 4 5 3 1 
2 5 4 3 1 
3 4 5 2 1 
3 5 4 2 1 
4 5 3 2 1 
5 4 3 2 1
 */