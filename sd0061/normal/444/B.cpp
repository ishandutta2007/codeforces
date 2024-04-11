#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
//#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;

const int N = 100005;
int n , d , a[N] , b[N] , res[N] , p[N];
LL x;
LL getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

void work() {
    int i , j , k;
    cin >> n >> d >> x;
    initAB();
    vector<int> c;
    for (i = 0 ; i < n ; ++ i) {
        if (b[i])
            c.push_back(i);
        p[a[i]] = i;
    }
    for (i = n ; i >= max(1 , n - 333) ; -- i) {
        k = p[i];
        for (j = 0 ; j < c.size() && k + c[j] < n ; ++ j)
            if (!res[k + c[j]])
                res[k + c[j]] = i;
    }
    for (i = 0 ; i < n ; ++ i) if (!res[i]){
        for (j = 0 ; j < c.size() && c[j] <= i ; ++ j)
            res[i] = max(res[i] , a[i - c[j]]);
    }
    for (i = 0 ; i < n ; ++ i)
        printf("%d\n" , res[i]);
}

int main()
{
    work();
    return 0;
}