#include <cstdio>
#include <algorithm>
using namespace std;
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
typedef long long ll;
const int Maxn=300000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int n;
ll s;
ll f[Maxn+5];
int qu[Maxn+5];
struct Node{
	ll v,c;
	friend bool operator <(Node a,Node b){
		if(a.c==b.c){
			return a.v<b.v;
		}
		return a.c<b.c;
	}
}a[Maxn+5];
ll calc(int i,ll x){
	return max(0ll,(x-f[i]+a[i].v-1)/a[i].v);
}
bool check(int i,int j,ll x){
	int f_i=calc(i,x),f_j=calc(j,x);
	if(f_i!=f_j){
		return f_i>f_j;
	}
	return f[i]+f_i*a[i].v<=f[j]+f_j*a[j].v;
}
ll slope(int i,int j){
	return (f[i]-f[j])/(a[j].v-a[i].v);
}
int main(){
	read(n),read(s);
	for(int i=1;i<=n;i++){
		read(a[i].v),read(a[i].c);
	}
	sort(a+1,a+1+n);
	int head=1,tail=0;
	ll v=0;
	ll ans=Inf;
	for(int i=1;i<=n;i++){
		if(a[i].v<=v){
			continue;
		}
		v=a[i].v;
		while(head<tail&&check(qu[head],qu[head+1],a[i].c)){
			head++;
		}
		if(i>1){
			f[i]=f[qu[head]]-a[i].c-calc(qu[head],a[i].c)*(a[i].v-a[qu[head]].v);
		}
		ans=min(ans,calc(i,s));
		while(head<tail&&slope(qu[tail-1],qu[tail])>=slope(qu[tail],i)){
			tail--;
		}
		qu[++tail]=i;
	}
	printf("%lld\n",ans);
	return 0;
}