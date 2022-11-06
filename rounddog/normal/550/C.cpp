#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
char s[120];
int n,m,a[120],x,y,z;

bool ffind()
{
	for (int i=0;i<n-2;i++)
	    for (int j=i+1;j<n-1;j++)
	        for (int k=j+1;k<n;k++){
	            if (a[i]!=0&&(a[i]*100+a[j]*10+a[k])%8==0){
	            	x=i,y=j,z=k;
	            	return true;
	            }
	        }
	for (int i=0;i<n-1;i++)
	    for (int j=i+1;j<n;j++)
	        if (a[i]!=0&&(a[i]*10+a[j])%8==0){
	        	x=i;y=j;z=-1;
	        	return true;
	        }
	for (int i=0;i<n;i++)
	    if (a[i]%8==0){
	    	x=i,y=-1,z=-1;
	    	return true;
	    }
	return false;
}
	        
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++) a[i]=s[i]-48;
	bool f=ffind();
	if (f){
	    printf("YES\n");
	    if (x!=-1) printf("%d",a[x]);
	    if (y!=-1) printf("%d",a[y]);
	    if (z!=-1) printf("%d",a[z]);
	    printf("\n");
	}
	else printf("NO\n");
	return 0;
}