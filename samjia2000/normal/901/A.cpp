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

const int N = 200005;

int h,a[N];
int n;

int main(){
	h=get();
	fo(i,0,h)a[i]=get();
	bool bz=1;
	fo(i,0,h-1)
	if (a[i]>1&&a[i+1]>1)bz=0;
	if (bz)return printf("perfect\n"),0;
	printf("ambiguous\n");
	fo(i,0,h){
		int pn=n;
		n+=a[i];
		if (i==0){
			fo(i,pn+1,n)printf("0 ");
		}
		else	fo(i,pn+1,n)printf("%d ",pn);
	}
	putchar('\n');
	n=0;
	fo(i,0,h){
		int pn=n;
		n+=a[i];
		if (i==0){
			fo(i,pn+1,n)printf("0 ");
		}
		else{
			if (a[i]==1||a[i-1]==1){
				fo(i,pn+1,n)printf("%d ",pn);
			}
			else{
				fo(i,pn+1,n-1)printf("%d ",pn);
				printf("%d ",pn-1);
			}
		}
	}
	putchar('\n');
	return 0;
}