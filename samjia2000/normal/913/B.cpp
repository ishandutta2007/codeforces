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
#define se second
#define fi first

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

int d[N],s[N];
int lef[N],rig[N];
int n;
bool ans;

int main(){
	n=get();
	fo(i,2,n){
		int x=get();
		rig[i]=lef[x];
		lef[x]=i;
		d[x]++;
	}
	ans=1;
	fo(x,1,n)
	if (d[x]){
		int cnt=0;
		for(int y=lef[x];y;y=rig[y])
		if (!d[y])cnt++;
		ans&=(cnt>2);
	}
	if (ans)printf("Yes\n");
	else printf("No\n");
	return 0;
}