#include<bits/stdc++.h>
using namespace std;

struct fe{
	int x,y;
	bool operator <(const fe &o)const{return x>o.x;}
}a[100005];
int n,s;
long long ans,t;
int main(){
	scanf("%d%d",&n,&s);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d%d",&a[i].y,&x,&y);
		ans+=1ll*a[i].y*x,t+=a[i].y;
		a[i].x=y-x;
	}
	if(t%s)a[n++]=(fe){0,s-t%s};
	sort(a,a+n);
	long long r=0,u=0,v=0;
	for(int i=0;i<n;i++){
		if(v+a[i].y>=s)r=max(r,max(1ll*(s-v)*a[i].x,1ll*((v+a[i].y)/s*s-v)*a[i].x)+u);
		u+=1ll*a[i].x*a[i].y;
		v=(v+a[i].y)%s;
	}
	printf("%I64d\n",ans+r);
	return 0;
}