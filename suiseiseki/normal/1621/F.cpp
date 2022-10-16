#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
int n,a,b,c;
char s[Maxn+5];
int lis[Maxn+5],len;
void solve(){
	scanf("%d%d%d%d",&n,&a,&b,&c);
	scanf("%s",s+1);
	int cnt_0=0,cnt_1=0;
	for(int i=1;i<n;i++){
		if(s[i]==s[i+1]){
			if(s[i]=='0'){
				cnt_0++;
			}
			else{
				cnt_1++;
			}
		}
	}
	len=0;
	int cnt_2=0,cnt_3=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		if(s[i]=='1'){
			continue;
		}
		while(j<=n&&s[j]=='0'){
			j++;
		}
		j--;
		if(i>1&&j<n){
			lis[++len]=j-i;
		}
		else{
			cnt_3++;
		}
	}
	std::sort(lis+1,lis+1+len);
	int tmp=std::min(cnt_0,cnt_1);
	cnt_0-=tmp,cnt_1-=tmp;
	ll ans=1ll*tmp*(a+b);
	for(int i=1;i<=len;i++){
		if(tmp>=lis[i]){
			tmp-=lis[i];
			cnt_2++;
		}
	}
	if(cnt_1){
		ans+=b;
		cnt_1--;
	}
	if(cnt_0){
		ans+=a;
		cnt_0--;
	}
	if(c<b){
		ans+=1ll*(b-c)*(cnt_2+std::min(cnt_3,cnt_1));
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}