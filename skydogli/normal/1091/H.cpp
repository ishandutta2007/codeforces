#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int n,ban,a,b,c;
int p[N+5],vis[N+5],cnt,sg[N+5];
bitset<N+5>tmp,f[105];
void init(int ban){
	for(int i=2;i<=N;++i){
		if(!vis[i]){p[++cnt]=i;tmp.set(i);}
		for(int j=1;p[j]*i<=N;++j){
			vis[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
	for(int i=1;i<=cnt;++i)
		for(int j=1;p[j]*p[i]<=N&&j<=i;++j)
			tmp.set(p[j]*p[i]);
	tmp.reset(ban);
	f[0]=tmp;
	for(int i=1;i<=N;++i){
		while(f[sg[i]][i]){
			sg[i]++;
		}
		f[sg[i]]|=(tmp<<i);
	}
}
int main(){
	scanf("%d%d",&n,&ban);
	init(ban);
	int ans=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a,&b,&c);
		ans^=sg[b-a-1]^sg[c-b-1];
	}
	puts(ans?"Alice\nBob":"Bob\nAlice");
	return 0;
}