#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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

const int N = 3e5+5;

int n;
struct node{
	int x,y;
}a[N];
int num[N],m;

bool cmp1(int x,int y){return a[x].x>a[y].x;}

bool cmp2(int x,int y){return a[x].y<a[y].y;}

int main(){
	n=get();
	int cnt1=0,cnt2=0;
	fo(i,1,n){
		a[i].x=get();a[i].y=get();
		if (a[i].x<a[i].y)cnt1++;
		if (a[i].x>a[i].y)cnt2++;
	}
	if (cnt1>cnt2){
		fo(i,1,n)
		if (a[i].x<a[i].y)num[++m]=i;
		sort(num+1,num+1+m,cmp1);
		printf("%d\n",m);
		fo(i,1,m)printf("%d ",num[i]);
		putchar('\n');
	}
	else{
		fo(i,1,n)
		if (a[i].x>a[i].y)num[++m]=i;
		sort(num+1,num+1+m,cmp2);
		printf("%d\n",m);
		fo(i,1,m)printf("%d ",num[i]);
		putchar('\n');
	}
	return 0;
}