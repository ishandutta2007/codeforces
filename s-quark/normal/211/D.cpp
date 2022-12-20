#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <complex>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef double du;
typedef long long ll;
typedef complex<du> com;
const int MAXN = 1000004;

int a[MAXN];
int st[MAXN];
com x[MAXN];

void insert(int a, int b, du h){
    //cout<<a<<" "<<b<<" "<<h<<endl;
    if(a > b)
        swap(a, b);
    com t(0., 1.);
    x[1] += t*(du)h;
    x[a] -= t*h;
    x[a] += com(a, 0.)*h;
    x[b] -= com(a, 0.)*h;
    x[b] += com(a+b, -1.)*h;
    x[a+b] -= com(a+b, -1.)*h;
}

int main(){
    #ifdef __FIO
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int n, m;
    int i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[0] = 0;
    a[n+1] = 0;
    j = 0;
    st[0] = 0;
    for(i = 1; i <= n+1; i++){
        while(j >= 0 && a[i] <= a[st[j]]){
            insert(st[j]-st[j-1], i-st[j], a[st[j]]);
            j--;
        }
        st[++j] = i;
    }
    for(i = 1; i <= n; i++)
        x[i] += x[i-1];
    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%d", &j);
        printf("%.15lf\n", (real(x[j]) + j*imag(x[j]))/(n+1-j));
    }
    return 0;
}