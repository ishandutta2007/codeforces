#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <bitset>
using namespace std;
typedef long long LL;
const int N = 2005;
int n , h[N];
vector<int> a[N];
void work() {
    int i , j , k , x;
    cin >> n;
    for (i = 1 ; i <= n ; ++ i) {
        cin >> x , h[i] = x;
        a[x].push_back(i);
    }
    vector<int> b[3];
    int res = 1;
    for (i = 1 ; i <= 2000 ; ++ i) {
        for (k = 0 ; k < a[i].size() ; ++ k)
            for (j = 0 ; j < 3 ; ++ j)
                b[j].push_back(a[i][k]);
    }
    for (i = 1 ; i < n ; ++ i)
        if (h[b[1][i]] == h[b[1][i - 1]]) {
            swap(b[1][i] , b[1][i - 1]);
            break;
        }
    for (++ i ; i < n ; ++ i)
        if (h[b[2][i]] == h[b[2][i - 1]]) {
            swap(b[2][i] , b[2][i - 1]);
            break;
        }
    if (b[0] == b[1] || b[1] == b[2] || b[2] == b[0])
        puts("NO");
    else {
        puts("YES");
        for (j = 0 ; j < 3 ; ++ j)
            for (i = 0 ; i < n ; ++ i)
                printf("%d%c" , b[j][i] , " \n"[i + 1 == n]);
    }

}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}