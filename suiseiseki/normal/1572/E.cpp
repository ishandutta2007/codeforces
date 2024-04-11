#include <cstdio>
#include <algorithm>
typedef long long ll;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
const int Inf_int=0x3f3f3f3f;
const int Maxn=200;
int n,K;
int x[Maxn+5],y[Maxn+5];
struct Node{
	ll area;
	int cnt;
	Node(ll _area=0,int _cnt=0){
		area=_area;
		cnt=_cnt;
	}
	friend bool operator <(Node a,Node b){
		if(a.cnt!=b.cnt){
			return a.cnt<b.cnt;
		}
		return a.area<b.area;
	}
}f[Maxn+5][Maxn+5];
ll cross(ll a,ll b,ll c,ll d){
	return a*d-b*c;
}
bool check(ll mid){
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			f[i][j]=Node(Inf_ll,-Inf_int);
		}
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i<=n;i++){
			int j=i+len-1;
			if(j>n){
				break;
			}
			for(int k=i+1;k<j;k++){
				Node cur=Node(f[i][k].area+f[k][j].area+cross(x[k]-x[i],y[k]-y[i],x[j]-x[i],y[j]-y[i]),f[i][k].cnt+f[k][j].cnt);
				if(cur.area>=mid){
					cur.area=0;
					cur.cnt++;
				}
				f[i][j]=std::max(f[i][j],cur);
			}
		}
	}
	return f[1][n].cnt>=K;
}
int main(){
	scanf("%d%d",&n,&K);
	K++;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	ll left=0,right=Inf_ll;
	while(left<right){
		ll mid=(left+right+1)>>1;
		if(check(mid)){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	printf("%lld\n",left);
	return 0;
}