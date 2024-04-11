#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=5005;
char s[N],t[N];
int n;

bool check()
{
	rep(i,1,n) if(t[i]!=t[n-i+1]) return 0;
	rep(i,1,n) if(t[i]!=s[i]) return 1;
	return 0;
}

void task()
{
	rep(i,1,n-1)
	{
		rep(j,i+1,n) t[j-i]=s[j];
		rep(j,1,i) t[j+n-i]=s[j];
		if(check()) {puts("1"); return;}
	}
	rep(i,1,n/2)
	{
		rep(j,1,n) t[j]=s[j];
		rep(j,1,i) swap(t[j],t[n-(i-j+1)+1]);
		if(check()) {puts("2"); return;}
	}
	puts("Impossible");
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	task();
	return 0;
}