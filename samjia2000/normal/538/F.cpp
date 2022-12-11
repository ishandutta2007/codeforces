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

const int N = 200010;

int a[N];
int n;
int f[N];

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	fo(i,2,n){
		int r=0;
		while(r<i-2){
			int l=r+1;
			r=(i-2)/((i-2)/l);
			int v=(i-2)/l+1;
			if (a[v]>a[i])f[l]++,f[r+1]--;
		}
		if (a[1]>a[i])f[i-1]++;
	}
	fo(i,1,n-1){
		f[i]+=f[i-1];
		printf("%d ",f[i]);
	}
	return 0;
}