#include<bits/stdc++.h>
using namespace std;

const int N=100100;
const double eps=1e-9;
struct db{
	long long a,b;
	db(){
		a=0,b=1;
	}
	db(long long x,long long y){
		long long d=__gcd(x,y);
		a=x/d;
		b=y/d;
		if(b<0){
			a=-a,b=-b;
		}
	}
	bool operator <(const db &o)const{
		return a*o.b<b*o.a;
	}
	bool operator ==(const db &o)const{return a==o.a&&b==o.b;}
	db operator -(const db &o)const{
		return db(a*o.b-b*o.a,b*o.b);
	}
	db operator *(const db &o)const{
		return db(a*o.a,b*o.b);
	}
};
struct atom{
	db x,y;
	bool operator <(const atom &o)const{return x<o.x||x==o.x&&y<o.y;}
}p[N];
int n,w,c[N],tr[N];
db a[N],b[N];
int calc(int x){
	int ans=0;
	for(;x;x-=x&-x){
		ans+=tr[x];
	}
	return ans;
}
void add(int x){
	for(;x<=n;x+=x&-x){
		tr[x]++;
	}
}
long long calc(db w,int f){
	memset(tr,0,sizeof(tr));
	for(int i=0;i<n;i++){
		a[i]=b[i]=p[i].y-p[i].x*w;
	}
	sort(b,b+n);
	int m=unique(b,b+n)-b;
	for(int i=0;i<n;i++)c[i]=lower_bound(b,b+m,a[i])-b+1;
	long long ans=0;
	for(int i=n-1;i>=0;i--){
		ans+=calc(c[i]-f);
		add(c[i]);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&w);
	for(int i=0;i<n;i++){
		int a,b;scanf("%d%d",&a,&b);
		p[i]=(atom){db(1,a),db(b,a)};
	}
	sort(p,p+n);
	long long ans=calc(db(w,1),0)-calc(db(-w,1),1);
	printf("%lld\n",ans);
	return 0;
}