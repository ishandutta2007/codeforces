#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;

int cnt[10];
int tk[10];
ll res=0;

void cal(){
	int tot=0;
	ll fm=1,fz=1;
	for(int i=0;i<10;++i){
		tot+=tk[i];
		for(int j=2;j<=tk[i];++j)
			fm*=j;
			
	}
	for(int i=2;i<=tot;++i)
		fz*=i;
	res+=fz/fm;
}

void dfs(int p){
	if(p==10){
		for(int i=1;i<10;++i){
			if(tk[i]){
				tk[i]--;
				cal();
				tk[i]++;
			}
		}
		//cout<<res<<"!!"<<endl;
		return ;
	}
	if(!cnt[p])
		dfs(p+1);
	else{
		for(int i=1;i<=cnt[p];++i){
			tk[p]=i;
			dfs(p+1);
			tk[p]=0;
		}
	}
}

signed main(){
	ll N;
	for(scanf("%lld",&N);N;N/=10)
		cnt[N%10]++;
	//for(int i=0;i<=9;++i) cout<<cnt[i]<<"!!"<<endl;
	dfs(0);
	printf("%lld\n",res);
	return 0;
}