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

const int N = 100005;
const int L = 60;

LL mi[L+3];
int q;
LL ad[L+3];

int main(){
	q=get();
	mi[0]=1;
	fo(i,1,L+1)mi[i]=mi[i-1]*2;
	fo(cas,1,q){
		int ty=get();
		LL x,k;
		if (ty==1){
			scanf("%I64d%I64d",&x,&k);
			int l=0;
			fo(i,0,L)
			if (x<mi[i+1]){l=i;break;}
			k=(k%mi[l]+mi[l])%mi[l];
			ad[l]=(ad[l]+k)%mi[l];
			k=(mi[l+1]-k*2%mi[l+1])%mi[l+1];
			ad[l+1]=(ad[l+1]+k)%mi[l+1];
		}
		if (ty==2){
			scanf("%I64d%I64d",&x,&k);
			int l=0;
			fo(i,0,L)
			if (x<mi[i+1]){l=i;break;}
			k=(k%mi[l]+mi[l])%mi[l];
			ad[l]=(ad[l]+k)%mi[l];
		}
		if (ty==3){
			scanf("%I64d",&x);
			LL ans=0;
			int l=0;
			fo(i,0,L)
			if (x<mi[i+1]){l=i;break;}
			for(;x;x=(((x^mi[l])+ad[l])%mi[l]+mi[l])/2,l--)printf("%I64d ",x);
			putchar('\n');
		}
	}
	return 0;
}