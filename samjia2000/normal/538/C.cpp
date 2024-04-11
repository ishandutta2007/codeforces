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

const int N = 100010;

struct day{
	int h,d;
}a[N];
int n,m;
int ans;

int main(){
	n=get();m=get();
	fo(i,1,m){a[i].d=get();a[i].h=get();}
	ans=max(a[1].h+a[1].d-1,a[m].h+n-a[m].d);
	fo(i,2,m){
		if (abs(a[i].h-a[i-1].h)>a[i].d-a[i-1].d){
			printf("IMPOSSIBLE\n");
			return 0;
		}
		ans=max(ans,(a[i].d-a[i-1].d-abs(a[i].h-a[i-1].h))/2+max(a[i].h,a[i-1].h));
	}
	printf("%d\n",ans);
	return 0;
}