#include <cstdio>
#include <cstring>
#define Maxn 100000
int Mod,phi_Mod;
int n;
int Pow[11][17*Maxn+5];
int phi(int n){
	int ans=n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			ans/=i;
			ans*=(i-1);
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n>1){
		ans/=n;
		ans*=(n-1);
	}
	return ans;
}
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		a=1ll*a*a%Mod;
		b>>=1;
	}
	return ans;
}
int p[15],len;
int work(int x,int *a){
	for(int i=1;i<=len;i++){
		a[i]=0;
		if(x%p[i]==0){
			while(x%p[i]==0){
				a[i]++;
				x/=p[i];
			}
		}
	}
	return x;
}
struct Segment_Node{
	int left,right;
	int sum,lazy;
	int a[15];
}seg[Maxn<<2|5];
int num[15];
int a[Maxn+5];
void push_up(int root){
	int l=seg[root<<1].sum,r=seg[root<<1|1].sum;
	for(int i=1;i<=len;i++){
		l=1ll*l*Pow[i][seg[root<<1].a[i]]%Mod;
		r=1ll*r*Pow[i][seg[root<<1|1].a[i]]%Mod;
//		l=1ll*l*ksm(p[i],seg[root<<1].a[i])%Mod;
//		r=1ll*r*ksm(p[i],seg[root<<1|1].a[i])%Mod;
	}
	seg[root].sum=(l+r)%Mod;
}
void push_down(int root){
	seg[root<<1].sum=1ll*seg[root<<1].sum*seg[root].lazy%Mod;
	seg[root<<1|1].sum=1ll*seg[root<<1|1].sum*seg[root].lazy%Mod;
	seg[root<<1].lazy=1ll*seg[root<<1].lazy*seg[root].lazy%Mod;
	seg[root<<1|1].lazy=1ll*seg[root<<1|1].lazy*seg[root].lazy%Mod;
	seg[root].lazy=1;
	for(int i=1;i<=len;i++){
		seg[root<<1].a[i]+=seg[root].a[i];
		seg[root<<1|1].a[i]+=seg[root].a[i];
		seg[root].sum=1ll*seg[root].sum*Pow[i][seg[root].a[i]]%Mod;
//		seg[root].sum=1ll*seg[root].sum*ksm(p[i],seg[root].a[i])%Mod;
		seg[root].a[i]=0;
	}
}
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	seg[root].lazy=1;
	if(left==right){
		seg[root].sum=work(a[left],seg[root].a);
		return;
	}
	memset(seg[root].a,0,sizeof seg[root].a);
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	push_up(root);
}
void update(int root,int x,int a){
	if(seg[root].left==seg[root].right){
		seg[root].sum=1ll*seg[root].sum*a%Mod;
		for(int i=1;i<=len;i++){
			seg[root].a[i]-=num[i];
		}
		return;
	}
	push_down(root);
	root<<=1;
	if(x<=seg[root].right){
		update(root,x,a);
	}
	root|=1;
	if(x>=seg[root].left){
		update(root,x,a);
	}
	root>>=1;
	push_up(root);
}
void update(int root,int left,int right,int a){
	if(seg[root].left==left&&seg[root].right==right){
		seg[root].sum=1ll*seg[root].sum*a%Mod;
		seg[root].lazy=1ll*seg[root].lazy*a%Mod;
		for(int i=1;i<=len;i++){
			seg[root].a[i]+=num[i];
		}
		return;
	}
	push_down(root);
	root<<=1;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			update(root,left,right,a);
		}
		else{
			update(root,left,seg[root].right,a);
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			update(root,left,right,a);
		}
		else{
			update(root,seg[root].left,right,a);
		}
	}
	root>>=1;
	push_up(root);
}
int query(int root,int left,int right){
	if(seg[root].left==left&&seg[root].right==right){
		int ans=seg[root].sum;
		for(int i=1;i<=len;i++){
			ans=1ll*ans*Pow[i][seg[root].a[i]]%Mod;
//			ans=1ll*ans*ksm(p[i],seg[root].a[i])%Mod;
		}
		return ans;
	}
	push_down(root);
	root<<=1;
	if(right<=seg[root].right){
		return query(root,left,right);
	}
	root|=1;
	if(left>=seg[root].left){
		return query(root,left,right);
	}
	root>>=1;
	return (query(root<<1,left,seg[root<<1].right)+query(root<<1|1,seg[root<<1|1].left,right))%Mod;
}
int main(){
	scanf("%d%d",&n,&Mod);
	phi_Mod=phi(Mod);
	int now=Mod;
	for(int i=2;i*i<=now;i++){
		if(now%i==0){
			p[++len]=i;
			while(now%i==0){
				now/=i;
			}
		}
	}
	if(now>1){
		p[++len]=now;
	}
	for(int i=1;i<=len;i++){
		Pow[i][0]=1;
		for(int j=1;j<=Maxn*17;j++){
			Pow[i][j]=1ll*Pow[i][j-1]*p[i]%Mod;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	int q;
	scanf("%d",&q);
	int op,l,r,x;
	while(q--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d",&l,&r,&x);
			x=work(x,num);
			update(1,l,r,x);
		}
		else if(op==2){
			scanf("%d%d",&l,&x);
			x=work(x,num);
			x=ksm(x,phi_Mod-1);
			update(1,l,x);
		}
		else if(op==3){
			scanf("%d%d",&l,&r);
			printf("%d\n",query(1,l,r));
		}
	}
	return 0;
}