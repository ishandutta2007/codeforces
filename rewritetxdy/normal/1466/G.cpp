#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e6+10;
const int p = 1e9+7;

int nxt[N],ext[N];

inline void getnxt(char *t){
	int x = 1,p = 1,n = strlen(t+1);
	nxt[1] = n;
	for(int i=2;i <= n;i++){
		if(i+nxt[i-x+1] >= p){
			if(i >= p) p = i;
			while(p <= n && t[p] == t[p-i+1]) p++;
			nxt[i] = p-i;
			x = i;
		}
		else
			nxt[i] = nxt[i-x+1];
	}
}

inline void getext(char *s,char *t){
	int x = 1,p = 1,m = strlen(s+1),n = strlen(t+1);
	getnxt(t);
	for(int i=1;i <= m;i++){
		if(i+nxt[i-x+1] >= p){
			if(i >= p) p = i;
			while(p <= m && p-i+1 <= n && s[p] == t[p-i+1]) p++;
			ext[i] = p-i;
			x = i;
		}
		else
			ext[i] = nxt[i-x+1];
	}
	ext[0] = ext[m+1] = 0;
}

char ss[110],c[N],cc[N],a[N],inva[N],invc[N];
ll sum[30][N/10],z[N],inv[N];
int n,q,k,vis[N];

int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",ss+1);
	scanf("%s",c+1);
	z[0] = 1;
	for(int i=1;i <= n;i++) z[i] = z[i-1]*2%p;
	inv[0] = 1;
	for(int i=1;i <= n;i++) inv[i] = inv[i-1]*(p-p/2)%p;
	for(int i=1;i <= n;i++) sum[c[i]-'a'][i] = z[n-i];
	
	for(int i=n-1;i >= 1;i--) for(int j=0;j <= 25;j++)
		sum[j][i] = (sum[j][i]+sum[j][i+1])%p;
	while(q--){
		scanf("%d",&k);
		scanf("%s",cc+1);
		ll ans = 0;
		int lc = strlen(cc+1),la = strlen(ss+1),kk=0;
		memcpy(a,ss,sizeof(ss));
		while(la < lc){
			kk++;
			a[la+1] = c[kk];
			for(int i=1;i <= la;i++) a[i+la+1] = a[i];
			la = la*2+1;
		}
		if(kk > k){
			puts("0");
			continue;
		}
		a[la+1] = 0;
		getext(a,cc);
		for(int i=1;i <= la;i++)
			if(ext[i] == lc) ans = (ans+z[k-kk])%p;
		for(int i=1;i <= lc;i++) vis[i] = 0;
		getext(cc,a);
		for(int i=1;i <= lc;i++)
			if(ext[i+1] == lc-i) vis[i]++;
		for(int i=1;i <= lc;i++) invc[i] = cc[lc-i+1]; invc[lc+1] = 0;
		for(int i=1;i <= la;i++) inva[i] = a[la-i+1]; inva[la+1] = 0;
		getext(invc,inva);
		for(int i=1;i <= lc;i++)
			if(ext[lc-i+2] == i-1) vis[i]++;
		for(int i=1;i <= lc;i++)
			if(vis[i] == 2)
				ans = (ans+(sum[cc[i]-'a'][kk+1]-sum[cc[i]-'a'][k+1]+p)*inv[n-k])%p;
		printf("%lld\n",ans);
	}
	return 0;
}