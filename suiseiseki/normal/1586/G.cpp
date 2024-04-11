#include <cstdio>
#include <cstring>
#include <algorithm>
const int Mod=1000000007;
const int Maxn=200000;
int n;
struct Node{
	int a,b;
	int id;
	friend bool operator <(Node a,Node b){
		return a.b<b.b;
	}
}a[Maxn+5];
bool vis[Maxn+5];
int s_len;
int f[Maxn+5];
namespace BIT{
	int f[Maxn<<1|5];
	void add(int x,int a){
		for(int i=x;i<=(n<<1);i+=(i&(-i))){
			f[i]=(f[i]+a)%Mod;
		}
	}
	int query(int x){
		int ans=0;
		for(int i=x;i>0;i-=(i&(-i))){
			ans=(ans+f[i])%Mod;
		}
		return ans;
	}
	int query(int l,int r){
		return (query(r)-query(l-1)+Mod)%Mod;
	}
	void clear(){
		memset(f,0,sizeof f);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].a,&a[i].b);
		a[i].id=i;
	}
	scanf("%d",&s_len);
	for(int i=1;i<=s_len;i++){
		int pos;
		scanf("%d",&pos);
		vis[pos]=1;
	}
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=(BIT::query(a[i].a,a[i].b)+1)%Mod;
		BIT::add(a[i].a,f[i]);
	}
	BIT::clear();
	int ans=0;
	for(int i=n;i>0;i--){
		if(vis[a[i].id]||BIT::query(a[i].a,(n<<1))){
			ans=(ans+f[i])%Mod;
			BIT::add(a[i].a,1);
		}
	}
	printf("%d\n",ans);
	return 0;
}