#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=50000;
typedef long long ll;
int n,m;
ll K;
int Mod;
int s[Maxn+5];
struct Operation{
	ll pos;
	int val,x;
	friend bool operator <(Operation p,Operation q){
		return p.pos<q.pos;
	}
}op[Maxn<<1|5];
struct Matrix{
	int a[2][2];
	Matrix(){
		a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;
	}
	friend Matrix operator *(Matrix a,Matrix b){
		Matrix ans;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					ans.a[i][j]=(ans.a[i][j]+1ll*b.a[i][k]*a.a[k][j])%Mod;
				}
			}
		}
		return ans;
	}
};
Matrix a[Maxn+5],tmp[Maxn+5],d[Maxn+5];
ll b[Maxn+5];
int len;
Matrix val[Maxn<<2|5];
void insert(int x,Matrix a,int root=1,int left=1,int right=n){
	if(left==right){
		val[root]=a;
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		insert(x,a,root<<1,left,mid);
	}
	else{
		insert(x,a,root<<1|1,mid+1,right);
	}
	val[root]=(val[root<<1]*val[root<<1|1]);
}
Matrix quick_power(Matrix a,ll b){
	Matrix ans;
	ans.a[0][0]=ans.a[1][1]=1;
	while(b){
		if(b&1){
			ans=(ans*a);
		}
		b>>=1;
		a=(a*a);
	}
	return ans;
}
int main(){
	scanf("%lld%d",&K,&Mod);
	if(K==0){
		puts("0");
		return 0;
	}
	if(Mod==1){
		puts("0");
		return 0;
	}
	if(K==1){
		puts("1");
		return 0;
	}
	scanf("%d",&n);
	ll bel_k=K/n;
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
		s[i]%=Mod;
	}
	s[n]=s[0];
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%lld%d",&op[i].pos,&op[i].val);
		op[i].pos;
		op[i].val%=Mod;
		op[i+m]=op[i];
		op[i+m].pos++;
		op[i].x=1;
	}
	m<<=1;
	sort(op+1,op+1+m);
	for(int i=1;i<=n;i++){
		a[i].a[0][0]=0;
		a[i].a[0][1]=1;
		a[i].a[1][0]=s[i-1];
		a[i].a[1][1]=s[i];
		insert(i,a[i]);
		tmp[i]=a[i];
	}
	while(op[m].pos>K){
		m--;
	}
	Matrix all=val[1];
	for(int i=1,j;i<=m;i=j+1){
		j=i;
		ll bel=(op[i].pos-1)/n;
		while(j<m&&bel==(op[j+1].pos-1)/n){
			j++;
		}
		for(int k=i;k<=j;k++){
			int pos=(op[k].pos-1)%n+1;
			tmp[pos].a[1][op[k].x]=op[k].val;
			insert(pos,tmp[pos]);
		}
		if(bel==bel_k){
			break;
		}
		d[++len]=val[1];
		b[len]=bel;
		for(int k=i;k<=j;k++){
			int pos=(op[k].pos-1)%n+1;
			tmp[pos]=a[pos];
			insert(pos,a[pos]);
		}
	}
	Matrix ans;
	ans.a[0][0]=ans.a[1][1]=1;
	ll last=0;
	for(int i=1;i<=len;i++){
		ans=ans*quick_power(all,b[i]-last);
		ans=ans*d[i];
		last=b[i]+1;
	}
	ans=ans*quick_power(all,bel_k-last);
	for(int i=1;i<=K%n;i++){
		ans=ans*tmp[i];
	}
	printf("%d\n",ans.a[0][1]);
	return 0;
}