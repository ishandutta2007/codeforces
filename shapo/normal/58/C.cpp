#include <cstdio>
#include <cmath>

#define maxn 100010

using namespace std;

int a[maxn], num_beg[maxn];
int n, res;

int min(const int &a, const int &b){
    if(a < b) return a;
    return b;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i = 0; i < maxn; ++i)num_beg[i] = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        if(a[i] - min(n - 1 - i, i) > 0)++num_beg[a[i] - min(n - 1 - i, i)];
    }
    res = 2 * maxn;
    for(int i = 1; i < maxn; ++i)res = min(res, n - num_beg[i]);
    printf("%d\n", res);
    return 0;
}