#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 41



void work()
{
    int n , k , i, j;
    cin >> n >> k;
    int m = n * k;
    if (k + k > n - 1) {
        puts("-1");
        return;
    }
    printf("%d\n" , m);
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= k ; ++ j) {
            printf("%d %d\n" , i , (i + j) > n ? i + j - n : i + j);
        }
    }
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
//while (scanf("%d",&n) , n)
        work();
    return 0;
}