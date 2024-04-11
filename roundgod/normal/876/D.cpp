#include<bits/stdc++.h>
#define MAXN 300005
using namespace std;
int n;
int a[MAXN];
set<int> s;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("1 ");
    s.clear();
    for(int i=1;i<=n;i++)
        s.insert(i);
    for(int i=0;i<n;i++)
    {
        set<int>::iterator it=s.find(a[i]);
        s.erase(it);
        if(i!=n-1)
        {
            it=s.end();
            it--;
            printf("%d ",i+2+*it-n);
        }
        else printf("1\n");
    }
    return 0;
}