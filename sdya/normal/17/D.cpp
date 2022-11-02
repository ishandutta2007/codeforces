#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

char b[1100000];
char n[1100000];
int c;
long long tenmods[1100000];
long long B[1100000];
long long N[1100000];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%s %s %d", &b, &n, &c);
    long long C = c;
    long long k = strlen(b), l = strlen(n);
    for (int i = 0; i < k; i ++)
        B[i] = (long long)(b[i] - '0');
    for (int i = 0; i < l; i ++)
        N[i] = (long long)(n[i] - '0');
    
    long long basemod = 0;
    for (int i = 0; i < k; i ++)
        basemod *= 10LL, basemod += B[i], basemod %= C;

    for (int i = k - 1; i >= 0; i --)
        if (B[i] == 0) B[i] = 9; else {B[i] --; break;}
    for (int i = l - 1; i >= 0; i --)
        if (N[i] == 0) N[i] = 9; else {N[i] --; break;}

    long long newmod = 0;
    for (int i = 0; i < k; i ++)
        newmod *= 10LL, newmod += B[i], newmod %= C;    
    
    tenmods[0] = basemod % C;
    tenmods[1] = 1LL;
    for (int i = 1; i <= 10; i ++)
        tenmods[1] *= tenmods[0], tenmods[1] %= C;

    for (int i = 2; i <= 1000005; i ++) tenmods[i] = 1LL;
    for (int i = 2; i <= 1000005; i ++)
        for (int j = 1; j <= 10; j ++)
            tenmods[i] *= tenmods[i-1], tenmods[i] %= C;
    long long res = 1;
    for (int i = 0; i < l; i ++)
        for (int j = 1; j <= N[i]; j ++)
            res *= tenmods[l - i - 1], res %= C;

    res *= newmod;
    res %= C;
    if (res == 0) res = C;
    cout << res << endl;

    return 0;
}