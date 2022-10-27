#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int NICO = 200000+10;
int a[NICO], n;
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        if(a[i] != 0) a[i] = NICO;
    }
    int pos = -NICO;
    for(int i=1;i<=n;i++)
    {
        if(a[i] == 0) pos = i;
        a[i] = min(a[i], i - pos);
    }
    pos = 2*NICO;
    for(int i=n;i>=1;i--)
    {
        if(a[i] == 0) pos = i;
        a[i] = min(a[i], pos - i);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ", a[i]);
    }
}