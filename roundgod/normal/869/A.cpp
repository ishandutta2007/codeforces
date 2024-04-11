#include<bits/stdc++.h>
#define MAXN 2005
using namespace std;
int n,x[MAXN],y[MAXN];
set<int> s;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
        s.insert(x[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&y[i]);
        s.insert(y[i]);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(s.find(x[i]^y[j])!=s.end()) cnt++;
    if(cnt&1) puts("Koyomi"); else puts("Karen");
    return 0;
}