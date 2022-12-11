#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 200005;

char s[200005];
int sta0[N],top0,sta1[N],top1;
int lst[N];
bool nxt[N];
int key[N],k;

int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	fo(i,1,n){
		if (s[i]=='0'){
			if (top1){
				nxt[sta1[top1]]=1;
				lst[i]=sta1[top1--];
				sta0[++top0]=i;
			}
			else sta0[++top0]=i;
		}
		else{
			if (!top0)return printf("-1\n"),0;
			else{
				nxt[sta0[top0]]=1;
				lst[i]=sta0[top0--];
				sta1[++top1]=i;
			}
		}
	}
	if (top1)return printf("-1\n"),0;
	int cnt=0;
	fo(i,1,n)if (!nxt[i])cnt++;
	printf("%d\n",cnt);
	fo(i,1,n)
	if (!nxt[i]){
		k=0;
		for(int x=i;x;x=lst[x])key[++k]=x;
		sort(key+1,key+1+k);
		printf("%d ",k);
		fo(j,1,k)printf("%d%c",key[j],j==k?'\n':' ');
	}
	return 0;
}