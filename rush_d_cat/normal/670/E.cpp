#include <iostream>
#include <cstdio>
using namespace std;
const int NICO = 500000 + 10;
int n, m, p;
int l[NICO], pre[NICO], nxt[NICO], cp[NICO], top;
int vis[NICO];
char s[NICO], s1[NICO];
int main()
{
    scanf("%d %d %d", &n, &m, &p);
    scanf("%s %s", s+1, s1+1);
    for(int i=1;i<=n;i++)
    {
        pre[i] = i-1;
        nxt[i] = i+1;
        if(s[i] == '(')
        {
            l[++top] = i;
        } else {
            cp[i] = l[top];
            cp[l[top]] = i;
            top --;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(s1[i] == 'L')
        {
            p = pre[p];
        } 
        if(s1[i] == 'R')
        {
            p = nxt[p];
        }
        if(s1[i] == 'D')
        {
            int x, y;
            if(s[p] == '(')
            {
                y = nxt[cp[p]];
                x = pre[p];
            } else {
                y = nxt[p];
                x = pre[cp[p]];
            }
            pre[y] = x; 
            nxt[x] = y;
            p = (y>=n)?x:y;
            vis[x+1]+=1, vis[y-1]-=1;
        }
    }
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        sum += vis[i];
        if(!sum && !vis[i]) printf("%c", s[i]);
    }
    printf("\n");
}