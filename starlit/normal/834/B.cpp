#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 1000005
#define K 26
using namespace std;
int n,k,fr[K],to[K],now,t1,t2;
char ch[N];
int main()
{
	scanf("%d%d%s",&n,&k,ch+1);
	for(int i=1;i<=n;i++)
	to[ch[i]-'A']=i;
	for(int i=n;i;i--)
	fr[ch[i]-'A']=i;
	sort(to,to+K);
	sort(fr,fr+K);
	while(!fr[t1])t1++;
	while(!to[t2])t2++;
	while(t1<K&&t2<K)
	{
		if(fr[t1]>to[t2])
		t2++,now--;
		else t1++,now++;
		if(now>k)
		{puts("YES");return 0;}
	}
	puts("NO");
}