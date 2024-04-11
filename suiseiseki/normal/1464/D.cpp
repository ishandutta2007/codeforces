#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=1000000;
const int Mod=1000000007;
int find_num(int n){
	int ans=1;
	while(n>4){
		ans=1ll*ans*3%Mod;
		n-=3;
	}
	ans=1ll*ans*n%Mod;
	return ans;
}
int lis[Maxn+5],lis_len;
int w[3];
bool vis[Maxn+5];
int a[Maxn+5];
int n;
int work(){
	w[0]=w[1]=w[2]=0;
	int ans=0;
	bool flag=0;
	for(int i=1;i<=lis_len;i++){
		ans+=(lis[i]-1)/3;
		w[lis[i]%3]++;
		if(lis[i]%3==1&&lis[i]>=4){
			flag=1;
		}
	}
	if(n%3==2){
		if(w[2]){
			w[2]--;
		}
		else{
			ans++;
			w[1]-=2;
		}
	}
	else if(n%3==1){
		if(w[2]-w[1]>=2){
			w[2]-=2;
		}
		else if(flag){
			ans--;
			w[1]--;
		}
		else if(w[2]>=1){
			w[2]--;
			w[1]--;
			ans++;
		}
		else if(w[1]>=4){
			w[1]-=4;
			ans+=2;
		}
		else{
			w[1]--;
			ans++;
		}
	}
	int k=min(w[1],w[2]);
	w[1]-=k;
	w[2]-=k;
	ans+=k;
	ans+=2*w[1]/3;
	ans+=w[2];
	return ans;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		vis[i]=0;
	}
	lis_len=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		int sz=0;
		for(int j=i;!vis[j];j=a[j]){
			vis[j]=1;
			sz++;
		}
		lis[++lis_len]=sz;
	}
	printf("%d %d\n",find_num(n),work());
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}