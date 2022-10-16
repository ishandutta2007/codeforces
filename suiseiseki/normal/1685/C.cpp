#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n;
char s[Maxn+5];
int sum[Maxn+5];
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	bool flag_0=1;
	for(int i=1;i<=n*2;i++){
		sum[i]=sum[i-1]+(s[i]=='('?1:-1);
		if(sum[i]<0){
			flag_0=0;
		}
	}
	if(flag_0){
		puts("0");
		return;
	}
	int l=0,r=0;
	for(int i=1;i<=n*2;i++){
		if(sum[i]<0){
			if(l==0){
				l=i;
			}
			r=i;
		}
	}
	r++;
	for(int i=l;i>0;i--){
		if(sum[i-1]>sum[l-1]){
			l=i;
		}
	}
	for(int i=r;i<=n*2;i++){
		if(sum[i]>sum[r]){
			r=i;
		}
	}
	std::reverse(s+l,s+1+r);
	bool flag_1=1;
	int cur=0;
	for(int i=1;i<=n*2;i++){
		cur+=(s[i]=='('?1:-1);
		if(cur<0){
			flag_1=0;
			break;
		}
	}
	if(flag_1){
		printf("1\n%d %d\n",l,r);
		return;
	}
	std::reverse(s+l,s+1+r);
	int pos=0;
	for(int i=1;i<=n*2;i++){
		if(sum[i]>sum[pos]){
			pos=i;
		}
	}
	printf("2\n1 %d\n%d %d\n",pos,pos+1,2*n);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}