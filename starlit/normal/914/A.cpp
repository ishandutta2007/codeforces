#include<bits/stdc++.h>
using namespace std;
int n,a,s,ans=-1e7;
int main()
{
	scanf("%d",&n);
	while(n--)
    {
        scanf("%d",&a);
        s=sqrt(a);
        if(a>ans&&s*s!=a)
        ans=a;
    }
    printf("%d",ans);
}