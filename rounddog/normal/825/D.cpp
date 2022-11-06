#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 1000005

using namespace std;

int next[maxn],n,m,ans,a[27],b[27],w,sum;
char s[maxn],t[maxn];
bool f;

int main()
{
	scanf("%s",s);
	scanf("%s",t); 
	n=strlen(s);m=strlen(t);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
    for (int i=0;i<n;i++)
    	if (s[i]!='?') a[s[i]-96]++;
    for (int i=0;i<m;i++)
        b[t[i]-96]++;
    ans=0;f=true;
    while (f){
    	ans++;
    	sum=0;
    	for (int i=1;i<=26;i++)
    	    sum+=max(a[i],b[i]*ans);
	    if (sum>n) f=false;
	}
	ans--;
	int j=1;
    while (a[j]>=b[j]*ans&&j<27) j++;
	for (int i=0;i<n;i++)
	    if (s[i]=='?'){
	    	if (j<27){
	    		s[i]=96+j;
	    		a[j]++;
	    		while (a[j]>=b[j]*ans&&j<27) j++;
	    	}
	    	else s[i]=97;
	    }
	for (int i=0;i<n;i++)
	    printf("%c",s[i]);
    printf("\n");
    return 0;
}