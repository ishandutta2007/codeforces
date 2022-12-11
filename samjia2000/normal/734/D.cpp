#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int get(){
	char ch;
	int s=0;
	bool bz=0;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-')bz=1;else s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	if (bz)return -s;
	return s;
}

const int N = 500010;

int w[8];
struct chess{
	int x,y;
	char ch;
}a[N];
int n;

int main(){
	n=get();
	int x=get(),y=get();
	fo(i,1,n){
		while(a[i].ch=getchar(),a[i].ch!='R'&&a[i].ch!='B'&&a[i].ch!='Q');
		a[i].x=get();a[i].y=get();
		if (a[i].x+a[i].y==x+y){
			if (a[i].x<x&&(!w[0]||a[i].x>a[w[0]].x))w[0]=i;
			if (a[i].x>x&&(!w[1]||a[i].x<a[w[1]].x))w[1]=i;
		}
		if (a[i].x-a[i].y==x-y){
			if (a[i].x<x&&(!w[2]||a[i].x>a[w[2]].x))w[2]=i;
			if (a[i].x>x&&(!w[3]||a[i].x<a[w[3]].x))w[3]=i;
		}
		if (a[i].y==y){
			if (a[i].x<x&&(!w[4]||a[i].x>a[w[4]].x))w[4]=i;
			if (a[i].x>x&&(!w[5]||a[i].x<a[w[5]].x))w[5]=i;
		}
		if (a[i].x==x){
			if (a[i].y<y&&(!w[6]||a[i].y>a[w[6]].y))w[6]=i;
			if (a[i].y>y&&(!w[7]||a[i].y<a[w[7]].y))w[7]=i;
		}
	}
	bool pd=0;
	fo(i,0,3)
	if (w[i]&&(a[w[i]].ch=='Q'||a[w[i]].ch=='B'))pd=1;
	fo(i,4,7)
	if (w[i]&&(a[w[i]].ch=='Q'||a[w[i]].ch=='R'))pd=1;
	if (pd)printf("YES\n");
	else printf("NO\n");
	return 0;
}