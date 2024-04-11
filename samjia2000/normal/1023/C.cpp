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

const int N = 2e5+5;

int n,k;
char s[N];
int sta[N],top;
bool ans[N];

int main(){
	n=get();k=get();
	scanf("%s",s+1);
	fo(i,1,n){
		if (s[i]=='(')sta[++top]=i;
		else{
			k-=2;
			ans[sta[top--]]=ans[i]=1;
		}
		if (!k)break;
	}
	fo(i,1,n)
	if (ans[i])putchar(s[i]);
	putchar('\n');
	return 0;
}