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

const int N = 1005;
const db eps = 1e-8;

int n,m;
int a[N],b[N];

void push(db &v,int c){
	db t=1.0*(v+m)/c;
	v=v-t;
}

bool check(db v){
	fo(i,1,n){
		int A=a[i],B=b[i%n+1];
		push(v,A);
		if (v<0)return 0;
		push(v,B);
		if (v<0)return 0;
	}
	return 1;
}

int main(){
	n=get();m=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n)b[i]=get();
	db l=0,r=2e9;
	db ans=-1;
	while(fabs(r-l)/r>eps){
		db mid=(l+r)/2;
		if (check(mid))ans=mid,r=mid;
		else l=mid;
	}
	if(ans<0)printf("-1\n");
	else printf("%.9lf\n",ans);
	return 0;
}