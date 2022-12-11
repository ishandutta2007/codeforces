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

const int N = 1e5+5;

int n;
char s[N];
int can[N];
int f[60],g[60];
char ans[N];

void add(int w,int x,int v){
	x=(1<<x);
	fo(i,0,(1<<6)-1)if ((x&i)>0)f[i]+=v;
	fo(i,0,(1<<6)-1)if ((can[w]&i)>0)g[i]+=v;
}

bool possible(){
	bool ret=1;
	fo(i,0,(1<<6)-1)ret&=(f[i]<=g[i]);
	return ret;
}

int main(){
//	freopen("data.in","r",stdin);
	scanf("%s",s+1);
	n=strlen(s+1);
	fo(i,1,n)can[i]=(1<<6)-1;
	for(int m=get();m;m--){
		int x=get();
		char cv[10];
		scanf("%s",cv+1);
		can[x]=0;
		fo(j,1,strlen(cv+1))can[x]|=(1<<(cv[j]-'a'));
	}
	fo(i,1,n)
		fo(j,0,(1<<6)-1)
		if ((can[i]&j)>0)g[j]++;
	fo(i,1,n){
		int now=(1<<(s[i]-'a'));
		fo(j,0,(1<<6)-1)
		if ((now&j)>0)f[j]++;
	}
	if (!possible())return printf("Impossible\n"),0;
	fo(i,1,n){
		fo(x,0,5)
		if (((can[i]&(1<<x))>0)){
			add(i,x,-1);
			if (possible()){
				ans[i]='a'+x;
				break;
			}
			add(i,x,1);
		}
	}
	fo(i,1,n)putchar(ans[i]);
	putchar('\n');
	return 0;
}