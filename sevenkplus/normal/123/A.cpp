#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[2000];int n,f[2000],a[2000],v[30];
bool pr(int x){for(int i=2;i<x;i++)if(x%i==0)return 0;return 1;}
int fa(int x){if(f[x]==x)return x;else return f[x]=fa(f[x]);}
int main()
{
	scanf("%s",s);n=strlen(s);
	if(n<=3){puts("YES");puts(s);return 0;}
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=2;i<=n;i++)if(pr(i))
		for(int j=2;j<=n/i;j++)f[fa(i*j)]=fa(i);
	for(int i=1;i<=n;i++)a[fa(i)]++;
	for(int i=0;i<n;i++)v[s[i]-'a']++;
	int p=max_element(a+1,a+n+1)-a;
	if(*max_element(v,v+26)<a[p]){puts("NO");return 0;}
	int c=max_element(v,v+26)-v;
	memset(s,0,sizeof s);
	for(int i=1;i<=n;i++)
		if(fa(i)==p)s[i-1]='a'+c,v[c]--;
	for(int i=0;i<n;i++)if(!s[i])
		for(int j=0;j<26;j++)if(v[j]){v[j]--,s[i]='a'+j;break;}
	puts("YES");puts(s);
	return 0;
}