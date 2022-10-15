#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int h[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&h[i]);
    int t=0;
	memset(cnt,0,sizeof(cnt));
	int max1=0,max2=0;
	for(int i=0;i<n;i++)
    {
        if(h[i]<max1&&h[i]<max2) continue;
        if(h[i]>max1)
        {
            cnt[h[i]]--;
            max2=max1;
            max1=h[i];
        }
        else
        {
            cnt[max1]++;
            max2=h[i];
        }
    }
    int res=1,ans=-1;
    for(int i=1;i<=n;i++)
        if(cnt[i]>ans) {res=i; ans=cnt[i];}
    printf("%d\n",res);
    return 0;
}