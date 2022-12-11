#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

const db eps = 1e-10;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	bool pd=0;
	int s=ch-'0';
	if (ch=='-'){pd=1;s=0;}
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	if (pd)return -s;
	else return s;
}

int n,k;
db s,v1,v2,ans;

db getv(db t){
	return v2*t+t*((v2-v1)/(v2+v1)+1)*(n-1)*v1;
}

int main(){
	scanf("%d%lf%lf%lf%d",&n,&s,&v1,&v2,&k);
	n=(n-1)/k+1;
	db l=0,r=s/v1;
	while(l+eps<=r){
		db mid=(l+r)/2;
		if (getv(mid)>=s){
			ans=mid;
			r=mid;
		}
		else l=mid;
	}
	printf("%.12lf\n",ans+ans*((v2-v1)/(v2+v1)+1)*(n-1));
	return 0;
}