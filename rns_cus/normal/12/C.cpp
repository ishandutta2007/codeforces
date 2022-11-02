//C 
#include<cstdio>
#include<string>
#include<map>
#include<memory.h>
#include<algorithm>
using namespace std;
#define N 120
int a[N], b[N], n, m, ansmin, ansmax, gas;
char s[N];
map<string, int> f;

int main(){
    f.clear();
    memset(b, 0, sizeof b);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i ++) scanf("%d", a + i);
    gets(s);
    gas = 1;
    for(int i = 0; i < m; i ++){
        gets(s);
        if(f[s]) b[f[s]] ++;
        else { f[s] = gas; b[gas ++] ++;}
    }
    sort(a, a + n);
    sort(b + 1, b + gas);
    ansmin = ansmax = 0;
    for(int i = 1; i < gas; i ++ ){
        ansmin += b[i] * a[gas - i - 1];
        ansmax += b[i] * a[n + i - gas];
    }
    printf("%d %d\n", ansmin, ansmax);
}