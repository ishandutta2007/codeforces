#include <cstdio>
#include <cmath>

#define maxn 10100
#define numdiv 10000

using namespace std;

int a, b, n;
int res[maxn];
int divs[numdiv];

int nod(const int &x, const int &y){
    int xx = x, yy = y;
    if(xx < yy){int tmp = xx; xx = yy; yy = tmp;}
    while(yy != 0){int tmp = xx % yy; xx = yy; yy = tmp;}
    return xx;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &a, &b);
    int n_div = nod(a, b), num = 0;
    bool sqr = false;
    for(int i = 1; i * i <= n_div; ++i){
        if(n_div % i == 0)++num;
        sqr = sqr || (i * i == n_div);
    }
    num *= 2; if(sqr) --num;
    int cur = 0;
    for(int i = 1; i * i <= n_div; ++i)
        if(n_div % i == 0){
            divs[cur] = i;
            ++cur;
            divs[num - cur] = n_div / i;
        }
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int low, high;
        scanf("%d%d", &low, &high);
        int l = -1, r = num;
        while(l < r - 1){
            int m = (l + r) / 2;
            if(divs[m] > high)r = m; else l = m;
        }
        if(l == -1 || divs[l] < low)printf("-1\n"); else printf("%d\n", divs[l]);
    }
    return 0;
}