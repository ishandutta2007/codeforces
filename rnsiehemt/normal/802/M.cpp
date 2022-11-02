#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
typedef long long ll;

int n, k, a[123456], ans;

int main() {
    scanf("%d %d", &n, &k);
    fo(i,0,n) scanf("%d", a+i);
    sort(a, a+n);
    fo(i,0,k) ans += a[i];
    printf("%d\n", ans);


    return 0;
}