#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define MAXN 200001
#define INF 1000000001
using namespace std;
int n; 
int a[MAXN];
char c[MAXN];
int main()
{
	scanf("%d",&n);
    scanf("%s",c);
    int ans=INF;
    for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
      if(c[i]=='R'&&c[i+1]=='L') ans=min(ans,(a[i+1]-a[i])/2);
    if(ans==INF) printf("-1"); else printf("%d",ans);
	return 0; 
 }