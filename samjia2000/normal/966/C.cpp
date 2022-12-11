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
LL a[N];
int k1,k2;
LL f1[N],f2[N];

int main(){
	n=get();
	fo(i,1,n)scanf("%I64d",&a[i]);
	k1=0;
	bool ans=1;
	for(LL now=(1ll<<59);now&&k1<n;now>>=1){
		k2=0;
		fo(i,1,n)f2[i]=0;
		int w=0;
		fo(i,1,n)
		if ((a[i]&now)>0&&a[i]<now*2){
			if (!w){
				f2[++k2]=a[i];
				w=1;
			}
			else{
				while(w<=k1&&(f1[w]&now)==0)f2[++k2]=f1[w++];
				if (w>k1)return printf("No\n"),0;
				f2[++k2]=f1[w++];
				f2[++k2]=a[i];
			}
		}
		if (k1){
			if(!w)w=1;
			while(w<=k1)f2[++k2]=f1[w++];
		}
		k1=k2;
		fo(i,1,k2)f1[i]=f2[i];
	}
	printf("Yes\n");
	fo(i,1,n)cout<<f1[i]<<" ";
	putchar('\n');
	return 0;
}