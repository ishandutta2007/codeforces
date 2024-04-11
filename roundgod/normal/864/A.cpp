#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,a[MAXN];
vector<int> G;
int main()
{
    scanf("%d",&n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(a[x]==0) cnt++;
        a[x]++;
    }
    if(cnt!=2) {printf("NO\n"); return 0; }
    for(int i=1;i<MAXN;i++)
        if(a[i]!=0) { if(a[i]!=n/2) {printf("NO\n");return 0;} else G.push_back(i);}
    printf("YES\n");
    for(int i=0;i<G.size();i++)
        printf("%d ",G[i]);
    return 0;
}