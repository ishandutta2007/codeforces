#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=200000;
const int Maxl=2000000;
const int Inf=0x3f3f3f3f;
int n,l;
struct Node{
	ll t,x,y;
	ll bel;
	int pos;
	friend bool operator <(Node a,Node b){
		if(a.pos==b.pos){
			return a.bel<b.bel;
		}
		return a.pos<b.pos;
	}
}a[Maxn+5];
int d_x[Maxl+5],d_y[Maxl+5];
ll find_f(ll x,ll y){
	lldiv_t ans=lldiv(x,y);
	return ans.quot+(ans.rem>>63);
}
ll find_c(ll x,ll y){
	lldiv_t ans=lldiv(x,y);
	return ans.quot+(ans.rem>0);
}
bool work(int *d){
	static int s[Maxl+5];
	ll s_l=0,s_r=l;
	for(int i=1;i<=n;i++){
		ll d_T=a[i].bel-a[i-1].bel;
		ll d_t=a[i].pos-a[i-1].pos;
		ll d_s=a[i].x-a[i-1].x;
		ll tmp_l,tmp_r;
		if(d_T==0){
			if(d_s<0||d_t>l){
				return 0;
			}
			continue;
		}
		else if(d_T>0){
			if(d_s<0){
				return 0;
			}
			tmp_l=find_c((d_s-d_t),d_T);
			tmp_r=find_f(d_s,d_T);
		}
		else{
			if(d_s>0){
				return 0;
			}
			tmp_l=find_c((-d_s),(-d_T));
			tmp_r=find_f((-d_s+d_t),(-d_T));
		}
		s_l=max(1ll*s_l,tmp_l);
		s_r=min(1ll*s_r,tmp_r);
	}
	if(s_l>s_r){
		return 0;
	}
	memset(s,-1,sizeof s);
	s[l]=s_l;
	for(int i=1;i<=n;i++){
		s[a[i].pos]=a[i].x-a[i].bel*s_l;
	}
	for(int i=l;i>0;i--){
		if(s[i]==-1){
			s[i]=s[i+1];
		}
	}
	int sum=0;
	for(int i=1;i<=l;i++){
		if(sum<s[i]){
			sum++;
			d[i]=1;
		}
		else{
			d[i]=0;
		}
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++){
		ll x,y;
		scanf("%lld%lld%lld",&a[i].t,&x,&y);
		if((a[i].t^x^y)&1){
			puts("NO");
			return 0;
		}
		a[i].x=((x+y+a[i].t)/2);
		a[i].y=((x-y+a[i].t)/2);
		a[i].bel=a[i].t/l;
		a[i].pos=a[i].t%l;
	}
	n++;
	a[n].t=0;
	a[n].x=0;
	a[n].y=0;
	a[n].bel=-1;
	a[n].pos=l;
	sort(a,a+1+n);
	if(!work(d_x)){
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;i++){
		swap(a[i].x,a[i].y);
	}
	if(!work(d_y)){
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;i++){
		swap(a[i].x,a[i].y);
	}
	for(int i=1;i<=l;i++){
		if(d_x[i]==0&&d_y[i]==0){
			putchar('L');
		}
		else if(d_x[i]==0&&d_y[i]==1){
			putchar('D');
		}
		else if(d_x[i]==1&&d_y[i]==0){
			putchar('U');
		}
		else{
			putchar('R');
		}
	}
	putchar('\n');
	return 0;
}