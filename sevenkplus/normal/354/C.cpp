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

#define N 1000010

int s[N];
int a[N], n, k;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++)
        scanf("%d", a+i);
    for (int i = 0; i < n; i ++)
        s[a[i]] ++;
    for (int i = 1; i < N; i ++)
        s[i] += s[i-1];
    sort(a, a+n);
    for (int i = a[0]; i >= 1; i --)
    {
        int la = 0; 
        int S = 0;
        for (int j = i; j < N; j += i)
        {
            S += s[min(j+k, N-1)] - s[max(la, j-1)];
            la = min(j+k, N-1);
            if (la == N-1) break;
        }
        if (S == n)
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}