#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<int> s[100000 + 10];
int n, m, x, y;
int c[100000 + 10], u[100000 + 10];
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &c[i]);u[c[i]] = 1;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d", &x, &y);
        if(c[x] != c[y]) 
        {
            s[c[x]].insert(c[y]);
            s[c[y]].insert(c[x]);
        }
    }
    int maxc = 0, p = -1;
    for(int i=1;i<=100000;i++)
    {
        if(!u[i]) continue;
        int tmp = max((int)s[i].size(), 1);
        if(tmp > maxc || (tmp == maxc && i < p) )
        {
            maxc = tmp;
            p = i;
        }
    }
    cout << p << endl;
}