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
#define INF 1000000000
#define N 5010

int n, m; 
int a[N]; 
int s[N]; 
int p[N], pl[N], pr[N], pz[N]; 

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) 
        s[i] = INF; 
    for (int i = 1; i <= m; i ++) {
        scanf("%d%d%d%d", p+i, pl+i, pr+i, pz+i); 
        if (p[i] == 1) {
            for (int j = pl[i]; j <= pr[i]; j ++) 
                a[j] += pz[i]; 
        } else {
            for (int j = pl[i]; j <= pr[i]; j ++) 
                s[j] = min(s[j], pz[i] - a[j]); 
        }
    }
    memset(a, 0, sizeof a); 
    for (int i = 1; i <= n; i ++) 
        a[i] = s[i]; 
    bool F = 1; 
    for (int i = 1; i <= m; i ++) {
        if (p[i] == 1) {
            for (int j = pl[i]; j <= pr[i]; j ++) 
                a[j] += pz[i]; 
        } else {
            int t = -INF; 
            for (int j = pl[i]; j <= pr[i]; j ++) 
                t = max(t, a[j]); 
            if (t != pz[i]) {F = 0; break; }
        }
    }
    if (F) {
        puts ("YES"); 
        for (int i = 1; i <= n; i ++) 
            printf("%d%c", s[i], i == n? '\n': ' '); 
    } else {
        puts ("NO"); 
    }
    return 0;
}