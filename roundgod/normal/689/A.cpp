#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,f1,f2,f3,f4;
char a[10];
int main()
{
	scanf("%d",&n);
	f1=0;
	f2=0;
	f3=0;
	f4=0;
		  scanf("%s",a);
	for(int i=0;i<n;i++)
	{

	  if(a[i]=='1'||a[i]=='4'||a[i]=='7'||a[i]=='0') f1=1;
	  if(a[i]=='7'||a[i]=='9'||a[i]=='0') f2=1;
	  if(a[i]=='3'||a[i]=='6'||a[i]=='9'||a[i]=='0') f3=1;
	  if(a[i]=='1'||a[i]=='2'||a[i]=='3') f4=1;
    }
    if(f1&&f2&&f3&&f4) printf("YES"); else printf("NO");
    return 0;
}