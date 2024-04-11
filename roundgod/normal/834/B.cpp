#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
using namespace std;
char a[MAXN];
pair<int,int> t[26];
int ans=-INF,x,k;
int main()
{
    scanf("%d %d",&x,&k);
    scanf("%s",a);
    for(int i=0;i<26;i++)
    {
        t[i].first=-1;
        t[i].second=-1;
    }
    for(int i=0;i<x;i++)
    {
        if(t[(int)a[i]-65].first==-1) t[(int)a[i]-65].first=i;
        if(t[(int)a[i]-65].second<i) t[(int)a[i]-65].second=i;
    }
    for(int i=0;i<x;i++)
    {
        int cnt=0;
        for(int j=0;j<26;j++)
            if(t[j].first!=-1&&i>=t[j].first&&i<=t[j].second) cnt++;
        ans=max(ans,cnt);
    }
    if(ans>k) printf("YES\n"); else printf("NO\n");
    return 0;
}