#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int f[2020][2020],h[2020];
int n,k,cnt;
string s[2020];

int work(int l,int r)
{
	if(l==r)return 0;
	int now=++cnt,nowmin=0x3f3f3f3f,mid;
	for(int i=l;i<r;i++)
		if(h[i]<nowmin)nowmin=h[i],mid=i;
	int L=work(l,mid),R=work(mid+1,r);
	for(int i=0;i<=mid-l+1;i++)
		for(int j=0;j<=r-mid;j++)
			f[now][i+j]=max(f[now][i+j],f[L][i]+f[R][j]+i*j*h[mid]);
	return now;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		cin>>s[i];
	sort(s+1,s+1+n);
	for(int i=1;i<n;i++)
		while(h[i]<s[i].length()&&h[i]<s[i+1].length()&&s[i][h[i]]==s[i+1][h[i]])h[i]++;
	printf("%d",f[work(1,n)][k]);
}