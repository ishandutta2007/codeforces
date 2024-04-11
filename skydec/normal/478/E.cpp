#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long LL;
int wave[1010000];int m,p,q;
LL n,k,base=1;
int wave2[1010000];int wave3[1010000];
void dfs(int x){
	if(x>=10000000)return;
	wave[++m]=x;wave2[m]=x;
	if(x<10){
		for(int j=0;j<=9;j++)if(j!=x)dfs(x*10+j);
	}
	else{
		int v=x%10;
		int v2=(x%100)/10;
		if(v>v2)for(int j=0;j<v;j++)dfs(x*10+j);
		else for(int j=v+1;j<=9;j++)dfs(x*10+j);
	}
}
inline bool cmp(const int &a,const int &b){
	if(a*1ll%n!=b*1ll%n)return a*1ll%n<b*1ll%n;
	return a<b;
}
void work(int x,int *a,int limit,int &l1,int &r1,bool kd){
	LL key=x;for(int i=1;i<=7;i++)key=key*10ll%n;
	key=n-key;key=key%n;
	
	l1=-1;
	int l=1;int r=limit;
	
	int v1,v2;
	v2=x%10;
	v1=(x%100)/10;
	
	int st,ed;st=limit+1;ed=0;
	
	if(a[limit]*1ll%n<key||a[1]*1ll%n>key){
		r1=0;l1=1;
		return;
	}
	
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid]*1ll%n<key)l=mid+1;
		else if(a[mid]*1ll%n==key)st=mid,r=mid;
		else r=mid;
	}
	if(a[l]*1ll%n==key&&l<st)st=l;
	
	if(st==limit+1){l1=1;r1=0;return;}
	
	l=1;r=limit;
	
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid]*1ll%n<key)l=mid+1;
		else if(a[mid]*1ll%n==key)ed=mid,l=mid+1;
		else r=mid;
	}
	if(a[l]*1ll%n==key&&ed<l)ed=l;
	
	if(st>ed){l1=1;r1=0;return;}
	
	
	l=st;r=ed;
	if(!kd){
		r1=ed;l1=r+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[mid]>=(v2+1)*1000000)l1=mid,r=mid;
			else l=mid+1;
		}
		if(a[l]>=(v2+1)*1000000)l1=l;
	}
	else{
		l1=st;r1=st-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[mid]<v2*1000000)r1=mid,l=mid+1;
			else r=mid;
		}
		if(a[l]<v2*1000000)r1=l;
	}
}
inline bool bolang(int x){
	if(x<1000000){
		return x/100000>(x/10000)%10;
	}
	return 1;
}
inline LL mul(LL a,LL b,LL mo){
	LL c=0;
	for(;b;b/=2ll,a=(a+a)%mo)if(b&1)c=(c+a)%mo;
	return c;
}
int main(){
	scanf("%I64d%I64d",&n,&k);
	if(mul(n,k,(LL)1e14)!=mul(n,k,((LL)1e14)+1ll)){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=9;i++)dfs(i);
	sort(wave+1,wave+1+m);
	int cnt=0;
	for(int i=1;i<=m;i++)if(wave[i]*1ll%n==0){
		cnt++;
		if(cnt*1ll==k){
			printf("%d\n",wave[i]);
			return 0;
		}
	}
	k-=cnt;
	for(int i=1;i<=m;i++)if(wave[i]>=100000&&bolang(wave[i])){
		int x=wave[i];
		if((x/100000)%10>(x/1000000))wave2[++p]=x;
		else wave3[++q]=x;
		//wave 2: 
		//wave 3:  
	}
	
	sort(wave2+1,wave2+1+p,cmp);
	sort(wave3+1,wave3+1+q,cmp);
	
	
	for(int i=1;i<=m;i++){
		int x=wave[i];int l,r;l=r=0;
		//printf("%d %I64d\n",x,k);
		if(x<10){
			work(x,wave2,p,l,r,1);
			if(l<=r){
				if(k<=r-l+1){
					LL ans=x;
					for(int j=1;j<=7;j++)ans*=10ll;
					printf("%I64d\n",ans+wave2[l+k-1]);
					return 0;
				}
				else k-=1ll*(r-l+1);
			}
			work(x,wave3,p,l,r,0);
			if(l<=r){
				if(k<=r-l+1){
					LL ans=x;
					for(int j=1;j<=7;j++)ans*=10ll;
					printf("%I64d\n",ans+wave3[l+k-1]);
					return 0;
				}
				else k-=1ll*(r-l+1);
			}
		}
		else 
		if((x%100)/10<x%10){
			work(x,wave2,p,l,r,1);
			if(l>r)continue;
			if(k<=r-l+1){
				LL ans=x;
				for(int j=1;j<=7;j++)ans*=10ll;
				printf("%I64d\n",ans+wave2[l+k-1]);
				return 0;
			}
			else k-=1ll*(r-l+1);
		}
		else{
			work(x,wave3,q,l,r,0);
			if(l>r)continue;
			if(k<=r-l+1){
				LL ans=x;
				for(int j=1;j<=7;j++)ans*=10ll;
				printf("%I64d\n",ans+wave3[l+k-1]);
				return 0;
			}
			else k-=1ll*(r-l+1);
		}
	}
	printf("%d\n",-1);
	return 0;
}