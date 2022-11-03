#include<bits/stdc++.h>
using namespace std;

struct fe{
	int len,nxt,pre;
	long long x;
}a[1100005];
int n,m,seed,vmax,rt,cnt;
int fexp(int x,int t,int p){
	if(!t)return 1;
	int tmp=fexp(x,t>>1,p);tmp=1ll*tmp*tmp%p;
	return (t&1)?1ll*tmp*x%p:tmp;
}
int rnd(){
	int ret=seed;
	seed=(seed*7ll+13)%1000000007;
	return ret;
}
void merge(int i){
	assert(a[i].nxt);
	a[i].len=a[i].len+a[a[i].nxt].len;
	a[i].nxt=a[a[i].nxt].nxt;
	if(a[i].nxt)a[a[i].nxt].pre=i;
}
void update(int i){
	if(!i)return;
	while(a[i].pre&&a[i].x==a[a[i].pre].x)i=a[i].pre,merge(i);
	while(a[i].nxt&&a[i].x==a[a[i].nxt].x)merge(i);
}
void split(int i,int c){
	assert(c>0||c<a[i].len);
	int now=cnt++;
	a[now]=(fe){a[i].len-c,a[i].nxt,i,a[i].x};
	a[i].len=c;a[i].nxt=now;
	if(a[now].nxt)a[a[now].nxt].pre=now;
}
int calc(long long x,int l,int r){
	int ans=0,s=0;
	for(int i=rt;i;i=a[i].nxt){
		int c=s+1,d=s+a[i].len;
		if(a[i].x<x&&c<=r&&d>=l){
			int a=max(c,l),b=min(d,r);
			ans+=b-a+1;
		}
		s=d;
	}
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	for(int i=1;i<=n;i++){
		a[i].x=(rnd()%vmax)+1;
		a[i].len=1;
//		if(317<=i&&i<=334)printf("%d %d\n",i,a[i].x);
	}
	rt=1;
	for(int i=1;i<n;i++)a[i].nxt=i+1,a[i+1].pre=i;
	cnt=n+1;
	for(int i=1;i;i=a[i].nxt)update(i);
	for(int i=1;i<=m;i++){
		int op=(rnd()%4)+1,l=(rnd()%n)+1,r=(rnd()%n)+1,x,y;
		if(l>r)swap(l,r);
		if(op==3)x=(rnd()%(r-l+1))+1;else x=(rnd()%vmax)+1;
		if(op==4)y=(rnd()%vmax)+1;
//		printf("%d %d %d %d %d\n",op,l,r,x,y);
		if(op==1){
			int s=0;
			for(int j=rt,k;j;j=k){
				k=a[j].nxt;
				int c=s+1,d=s+a[j].len;
				for(int _=0;_<1;_++){
					if(d<l||c>r)continue;
					if(l<=c&&d<=r)a[j].x+=x;
					else{
						int now=j;
						if(l>c){
							split(now,l-c);
							now=cnt-1;
						}
						if(r<d){
							split(now,a[now].len-d+r);
						}
						a[now].x+=x;
					}
				}
				s=d;
			}
		}else if(op==2){
			int s=0;
			for(int j=rt,k;j;j=k){
				k=a[j].nxt;
				int c=s+1,d=s+a[j].len;
				for(int _=0;_<1;_++){
					if(d<l||c>r)continue;
					if(l<=c&&d<=r)a[j].x=x;
					else{
						int now=j;
						if(l>c){
							split(now,l-c);
							now=cnt-1;
						}
						if(r<d){
							split(now,a[now].len-d+r);
						}
						a[now].x=x;
					}
				}
				s=d;
			}
		}else if(op==3){
			long long h=0,t=(2e14);
			while(h<t){
				long long mid=h+t+1>>1;
				if(calc(mid,l,r)<x)h=mid;else t=mid-1;
			}
			printf("%lld\n",h);
		}else{
			int ans=0,s=0;
			for(int i=rt;i;i=a[i].nxt){
				int c=s+1,d=s+a[i].len;
				if(c<=r&&d>=l){
					int A=max(c,l),B=min(d,r);
					ans=(ans+1ll*fexp(a[i].x%y,x,y)*(B-A+1))%y;
				}
				s=d;
			}
			printf("%d\n",ans);
		}
		for(int i=rt;i;i=a[i].nxt)update(i);
//		for(int i=rt;i;i=a[i].nxt)printf("%d %lld  ",a[i].len,a[i].x);printf("\n");
//		int S=0;for(int i=rt;i;i=a[i].nxt)S+=a[i].len;printf("%d\n",S);
	}
	return 0;
}