#include <cstdio>
typedef long long ll;
const int Maxn=500000;
ll cnt[Maxn+5];
char s[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	ll ans=0;
	ll now=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		if(s[i]=='0'){
			ans+=now;
			cnt[0]++;
			continue;
		}
		while(j<=n&&s[j]=='1'){
			j++;
		}
		j--;
		int len=j-i+1;
		for(int k=1;k<=len;k++){
			now+=cnt[k-1];
			cnt[k]+=cnt[k-1];
			cnt[k-1]=0;
			ans+=now;
		}
		for(int k=1;k<=len;k++){
			ans+=1ll*k*(len-k+1);
			cnt[k]++;
			now+=k;
		}
	}
	printf("%lld\n",ans);
	return 0;
}