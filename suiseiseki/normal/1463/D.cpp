#include <cstdio>
const int Maxn=200000;
int n;
bool vis[Maxn<<1|5];
int a[Maxn+5],b[Maxn+5];
void init(){
	for(int i=1;i<=(n<<1);i++){
		vis[i]=0;
	}
}
bool check_1(int x){
	for(int i=n-x+1,j=1;i<=n;i++,j++){
		if(b[i]<a[j]){
			return 0;
		}
	}
	return 1;
}
bool check_2(int x){
	for(int i=x,j=n;i>0;i--,j--){
		if(b[i]>a[j]){
			return 0;
		}
	}
	return 1;
}
void solve(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		vis[b[i]]=1;
	}
	int len_a=0;
	for(int i=1;i<=(n<<1);i++){
		if(!vis[i]){
			a[++len_a]=i;
		}
	}
	int l_1=0,r_1=n,l_2=0,r_2=n;
	while(l_1<r_1){
		int mid=(l_1+r_1+1)>>1;
		if(check_1(mid)){
			l_1=mid;
		}
		else{
			r_1=mid-1;
		}
	}
	while(l_2<r_2){
		int mid=(l_2+r_2+1)>>1;
		if(check_2(mid)){
			l_2=mid;
		}
		else{
			r_2=mid-1;
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		if(i>l_2||(n-i)>l_1){
			continue;
		}
		ans++;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}