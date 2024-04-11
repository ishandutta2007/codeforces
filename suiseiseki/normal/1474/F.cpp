#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=50;
const int Mod=998244353;
int n;
int a[Maxn+5],a_len;
int m;
struct Matrix{
	int a[Maxn+5][Maxn+5];
	void init_zero(){
		for(int i=0;i<=m;i++){
			for(int j=0;j<=m;j++){
				a[i][j]=0;
			}
		}
	}
	void init(){
		for(int i=0;i<=m;i++){
			for(int j=0;j<=m;j++){
				a[i][j]=(i==j);
			}
		}
	}
	friend Matrix operator *(Matrix a,Matrix b){
		Matrix ans;
		ans.init_zero();
		for(int i=0;i<=m;i++){
			for(int k=0;k<=m;k++){
				for(int j=0;j<=m;j++){
					ans.a[i][j]=(ans.a[i][j]+1ll*a.a[i][k]*b.a[k][j])%Mod;
				}
			}
		}
		return ans;
	}
};
Matrix quick_power(Matrix a,int b){
	Matrix ans;
	ans.init();
	while(b){
		if(b&1){
			ans=ans*a;
		}
		b>>=1;
		a=a*a;
	}
	return ans;
}
struct Vector{
	int a[Maxn+5];
	void init_zero(){
		for(int i=0;i<=m;i++){
			a[i]=0;
		}
	}
	friend Vector operator *(Vector a,Matrix b){
		Vector ans;
		ans.init_zero();
		for(int i=0;i<=m;i++){
			for(int j=0;j<=m;j++){
				ans.a[j]=(ans.a[j]+1ll*a.a[i]*b.a[i][j])%Mod;
			}
		}
		return ans;
	}
};
struct Segment{
	ll l,r;
}seg[Maxn+5];
int seg_len;
ll d[Maxn*6+5];
int d_len;
int solve(int l,int r){
	m=r-l+1;
	seg_len=0;
	ll x=0;
	for(int i=l;i<=r;i++){
		seg_len++;
		seg[seg_len].l=(x+(a[i]<0?-1:1));
		seg[seg_len].r=x+a[i];
		x+=a[i];
	}
	seg[1].l=0;
	d_len=0;
	for(int i=1;i<=seg_len;i++){
		d[++d_len]=seg[i].l-1;
		d[++d_len]=seg[i].l;
		d[++d_len]=seg[i].l+1;
		d[++d_len]=seg[i].r-1;
		d[++d_len]=seg[i].r;
		d[++d_len]=seg[i].r+1;
	}
	sort(d+1,d+1+d_len);
	d_len=unique(d+1,d+1+d_len)-d-1;
	d_len--;
	Vector ans;
	ans.init_zero();
	ans.a[0]=1;
	ll lst=-1;
	for(int i=1;i<=d_len;i++){
		Matrix tmp;
		tmp.init_zero();
//		printf("Solving: %lld\n",d[i]);
		for(int j=1;j<=seg_len;j++){
			if(min(seg[j].l,seg[j].r)<=lst+1&&max(seg[j].l,seg[j].r)>=d[i]){
//				printf("In: %d\n",j);
				if(seg[j].l<seg[j].r){
					for(int k=0;k<=j;k++){
						tmp.a[k][j]=1;
//						printf("%d-->%d\n",k,j);
					}
				}
				else{
					for(int k=0;k<j;k++){
						tmp.a[k][j]=1;
//						printf("%d-->%d\n",k,j);
					}
				}
			}
		}
		tmp=quick_power(tmp,d[i]-lst);
		/*for(int j=0;j<=m;j++){
			for(int k=0;k<=m;k++){
				printf("%d ",tmp.a[j][k]);
			}
			puts("");
		}*/
		ans=ans*tmp;
		/*puts("Ansewr: ");
		for(int j=0;j<=m;j++){
			printf("%d ",ans.a[j]);
		}
		puts("");
		puts("");*/
		lst=d[i];
	}
	int sum=0;
	for(int i=0;i<=m;i++){
		sum=(sum+ans.a[i])%Mod;
	}
	return sum;
}
int main(){
	scanf("%d%*d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(x!=0){
			a[++a_len]=x;
		}
	}
	n=a_len;
	ll ans=0;
	ll sum=0;
	for(int i=1;i<=n;i++){
		ll tmp=sum;
		for(int j=i;j<=n;j++){
			tmp+=a[j];
			ans=max(ans,tmp-sum);
		}
		sum+=a[i];
	}
	if(ans==0){
		int val=1;
		for(int i=1;i<=n;i++){
			val=(val-a[i])%Mod;
		}
		printf("%lld %d\n",ans+1,val);
		return 0;
	}
	sum=0;
	int val=0;
	for(int i=1;i<=n;i++){
		ll tmp=sum;
		int right=-1;
		for(int j=i;j<=n;j++){
			tmp+=a[j];
			if(tmp-sum==ans){
				right=j;
			}
		}
		sum+=a[i];
		if(right!=-1){
			val=(val+solve(i,right))%Mod;
			i=right;
		}
	}
	printf("%lld %d\n",ans+1,val);
	return 0;
}