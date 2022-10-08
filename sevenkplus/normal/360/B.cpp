#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 2010

int n, k, a[N]; 
int f[N]; 

bool can (int d) {
    for (int i = 1; i <= n; i ++) f[i] = 1; 
    for (int i = 2; i <= n; i ++)
        for (int j = 1; j < i; j ++) 
            if (abs(a[i]-a[j])<=(ll)(i-j)*d) 
                f[i] = max(f[i], f[j]+1); 
    int S = 0; 
    for (int i = 1; i <= n; i ++) 
        S = max(S, f[i]); 
    return n-S <= k; 
}

int main()
{
    scanf("%d%d", &n, &k); 
    for (int i = 1; i <= n; i ++) 
        scanf("%d", a+i); 
        
    int le = 0, ri = 2*1000000000; 
    while (le <= ri) {
        int mi = ((ll)le + ri) / 2; 
        if (can (mi)) ri = mi - 1; else le = mi + 1; 
    }
    printf ("%d\n", le); 
    return 0;
}