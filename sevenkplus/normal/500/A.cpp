#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 100010

int n, t;
int a[N]; bool f[N];

int main () {
    cin >> n >> t; t --;
    for (int i = 0; i < n-1; i ++) cin >> a[i];
    f[t] = 1;
    for (int i = t-1; i >= 0; i --)
        f[i] = f[i+a[i]];
    puts (f[0]?"YES":"NO");
    return 0; 
}