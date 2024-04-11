#include <bits/stdc++.h>
using namespace std;
const int N=400000+10;
int n,a[N],b[N],pre[(1<<25)+1][2];
int main() {
	scanf("%d",&n);
	int ans=0;
	int odd=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]%2==0) odd++;
	}
	if(1LL*odd*(n-odd)%2) ans+=1;
	for(int i=1;i<25;i++){
		int mask=(1<<(i+1))-1;
		for(int j=1;j<=n;j++) b[j]=(a[j]&mask);
		for(int j=1;j<=n;j++){
			//printf("# %d\n", b[j]);
			if(b[j]>>i&1){
				pre[b[j]-(1<<i)][1]++;
			}else{
				pre[b[j]][0]++;
			}
		}
		int lim=1<<i;
		for(int j=1;j<=(1<<i);j++){
			pre[j][0]+=pre[j-1][0];
			pre[j][1]+=pre[j-1][1];
		}
		long long cnt=0;
		for(int j=1;j<=n;j++){
			//printf("%d\n", b[j]);
			if(b[j]>>i&1){
				int now=b[j]-(1<<i);
				cnt+=((lim-now-1>=0)?pre[lim-now-1][0]:0);
				cnt+=pre[1<<i][1] - ((lim-now-1>=0)?pre[lim-now-1][1]:0);
				//printf("# %d %d\n", pre[1<<i][1],  ((lim-now-1>=0)?pre[lim-now-1][1]:0));
				if(now+now>=lim) cnt--;
			}else{
				int now=b[j];
				cnt+=((lim-now-1>=0)?pre[lim-now-1][1]:0);
				cnt+=pre[1<<i][0] - ((lim-now-1>=0)?pre[lim-now-1][0]:0);
				if(now+now>=lim) cnt--;
			}
			//printf("cnt=%d\n", cnt);
		}
		//printf("i=%d,cnt=%d\n", i,cnt);
		if((cnt/2)&1) ans+=1<<i;
		for(int j=0;j<=(1<<i);j++){
			pre[j][0]=pre[j][1]=0;
		}
	}
	cout<<ans<<endl;
}