#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int trie[2000010][26],fail[2000010],last[2000010],o=1,is[2000010],ki[2000010],en[100010],fa[2000010],v[2000010],num[2000010];
char s[2000010];
queue<int> q;
void go(int i,int j)
{
	if(i==0)
		return;
	if(v[i]==j)
		return;
	num[i]++;
	v[i]=j;
	go(last[i],j);
}
int main()
{
	int n;
	cin>>n;
	printf("? ");
	for(int i=1;i<=n;i++)
		putchar('0');
	cout<<endl;
	fflush(stdout);
	int t1,t2;
	scanf("%d",&t1);
	printf("? 1");
	for(int i=2;i<=n;i++)
		putchar('0');
	cout<<endl;
	fflush(stdout);
	scanf("%d",&t2);
	if(t2<t1)
	{
		int l=1,r=n;
		printf("? ");
		for(int i=1;i<=n;i++)
			putchar('1');
		cout<<endl;
		fflush(stdout);
		int x,y;
		scanf("%d",&x);
		while(l!=r)
		{
			int mid=(l+r)>>1;
			printf("? ");
			for(int i=1;i<l;i++)
				putchar('1');
			for(int i=l;i<=mid;i++)
				putchar('0');
			for(int i=mid+1;i<=n;i++)
				putchar('1');
			cout<<endl;		
			fflush(stdout);	
			scanf("%d",&y);
			if(y-x==mid-l+1)
				l=mid+1;
			else
				r=mid;
		}
		printf("! %d %d",l,1);
	}
	else
	{
		int l=1,r=n;
		printf("? ");
		for(int i=1;i<=n;i++)
			putchar('0');
		cout<<endl;
		fflush(stdout);
		int x,y;
		scanf("%d",&x);
		while(l!=r)
		{
			int mid=(l+r)>>1;
			printf("? ");
			for(int i=1;i<l;i++)
				putchar('0');
			for(int i=l;i<=mid;i++)
				putchar('1');
			for(int i=mid+1;i<=n;i++)
				putchar('0');
			cout<<endl;		
			fflush(stdout);	
			scanf("%d",&y);
			if(y-x==mid-l+1)
				l=mid+1;
			else
				r=mid;
		}
		printf("! %d %d",1,l);
	}		
}