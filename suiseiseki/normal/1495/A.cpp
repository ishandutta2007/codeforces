#include <cmath>
#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int a[Maxn+5],b[Maxn+5];
int a_len,b_len;
int n;
void solve(){
	double ans=0;
	scanf("%d",&n);
	a_len=b_len=0;
	for(int i=1;i<=(n<<1);i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==0){
			a[++a_len]=(y<0?-y:y);
		}
		else{
			b[++b_len]=(x<0?-x:x);
		}
	}
	std::sort(a+1,a+1+a_len);
	std::sort(b+1,b+1+b_len);
	for(int i=1;i<=n;i++){
		ans+=sqrt(1ll*a[i]*a[i]+1ll*b[i]*b[i]);
	}
	printf("%.10lf\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}