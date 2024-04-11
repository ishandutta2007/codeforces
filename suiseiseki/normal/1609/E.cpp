#include <cstdio>
#include <algorithm>
const int Maxn=100000;
const int Inf=0x3f3f3f3f;
struct Value{
	int a[6];
	friend Value operator +(Value a,Value b){
		Value ans;
		ans.a[0]=a.a[0]+b.a[0];
		ans.a[1]=std::min(a.a[0]+b.a[3],std::min(a.a[1]+b.a[3],a.a[0]+b.a[1]));
		ans.a[2]=std::min(std::min(a.a[0]+std::min(std::min(b.a[5],b.a[4]),b.a[2]),a.a[1]+std::min(b.a[4],b.a[5])),a.a[2]+b.a[5]);
		ans.a[3]=a.a[3]+b.a[3];
		ans.a[4]=std::min(a.a[3]+std::min(b.a[4],b.a[5]),a.a[4]+b.a[5]);
		ans.a[5]=a.a[5]+b.a[5];
		for(int i=0;i<6;i++){
			ans.a[i]=std::min(ans.a[i],Inf);
		}
		return ans;
	}
};
int n,q;
Value val[Maxn<<2|5];
char s[Maxn+5];
void build(int root=1,int left=1,int right=n){
	if(left==right){
		for(int i=0;i<6;i++){
			val[root].a[i]=1;
		}
		if(s[left]=='a'){
			val[root].a[3]=val[root].a[5]=0;
		}
		else if(s[left]=='b'){
			val[root].a[0]=val[root].a[5]=0;
		}
		else{
			val[root].a[0]=val[root].a[3]=0;
		}
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	val[root]=val[root<<1]+val[root<<1|1];
}
void update(int x,int root=1,int left=1,int right=n){
	if(left==right){
		for(int i=0;i<6;i++){
			val[root].a[i]=1;
		}
		if(s[left]=='a'){
			val[root].a[3]=val[root].a[5]=0;
		}
		else if(s[left]=='b'){
			val[root].a[0]=val[root].a[5]=0;
		}
		else{
			val[root].a[0]=val[root].a[3]=0;
		}
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		update(x,root<<1,left,mid);
	}
	else{
		update(x,root<<1|1,mid+1,right);
	}
	val[root]=val[root<<1]+val[root<<1|1];
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	build();
	for(int i=1;i<=q;i++){
		int pos;
		char op[5];
		scanf("%d",&pos);
		scanf("%s",op);
		s[pos]=(*op);
		update(pos);
		int ans=Inf;
		for(int i=0;i<6;i++){
			ans=std::min(ans,val[1].a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}