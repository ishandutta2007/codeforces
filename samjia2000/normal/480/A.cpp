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

struct man{
	int x,y;
	friend bool operator < (man a,man b){
		if (a.x!=b.x)return a.x<b.x;
		return a.y<b.y;
	}
}a[5010];
int n;

int main(){
	n=get();
	fo(i,1,n){
		a[i].x=get();a[i].y=get();
	}
	sort(a+1,a+1+n);
	int w=0;
	fo(i,1,n){
		if (w<=a[i].y)w=a[i].y;
		else w=a[i].x;
	}
	printf("%d\n",w);
	return 0;
}