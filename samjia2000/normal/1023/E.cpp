#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
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

const int N = 1005;

char ans[N];
int n;

bool query(int x0,int y0,int x1,int y1){
	if (x0<1||x0>n||y0<1||y0>n)return 0;
	if (x1<1||x1>n||y1<1||y1>n)return 0;
	printf("? %d %d %d %d\n",x0,y0,x1,y1);
	fflush(stdout);
	char s[10];
	scanf("%s",s+1);
	return s[1]=='Y';
}

int main(){
	n=get();
	int x=n,y=n;
	fd(i,n*2-2,n){
		if (query(1,1,x-1,y)){
			ans[i]='D';
			x--;
		}
		else{
			ans[i]='R';
			y--;
		}
	}
	x=1,y=1;
	fo(i,1,n-1){
		if (query(x,y+1,n,n)){
			ans[i]='R';
			y++;
		}
		else{
			ans[i]='D';
			x++;
		}
	}
	ans[n*2-1]='\n';
	printf("! %s",ans+1);
	return 0;
}