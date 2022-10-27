#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef long long LL;
const LL mod=1000000007;
const int NICO = 2000000;
char a[NICO], b[NICO];
int c[NICO], ok[NICO], n, m;

bool check(int x)
{
    int p = 1;
    for(int i=1;i<=x;i++)
    {
        ok[c[i]] = x;
    }
    for(int i=1;i<=n;i++)
    {
        if(b[p] == a[i] && ok[i] != x)
        {
            p ++;
        }
        if(p == m+1)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%s %s", a+1, b+1);
    n = strlen(a+1);
    m = strlen(b+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &c[i]);
    }    
    int l = 0, r = n, ans;
    while(r - l > 1)
    {
        int mid = (l+r)/2;
        if(check(mid))
        {
            l = mid;
        } else {
            r = mid;
        }   
    } 
    if(check(l)) ans = l;
    if(check(r)) ans = r;
    cout << ans << endl;
}