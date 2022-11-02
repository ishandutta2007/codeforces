#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1010;
const ll p = 1e9+7;

ll n,c[N][N],sum[N][N][8],l[N][N][8],ans=1,ansi,ansj,ansl,anst;
double lg[N][N][8],maxn = -1;
char ss[N];

inline ll pw(ll x,ll y){
	ll ans = 1;
	while(y){
		if(y&1) ans = ans*x%p;
		x = x*x%p , y >>= 1;
	}
	return ans;
}

inline ll inv(ll x){
	if(!x) return 1;
	return pw(x,p-2);
}

inline void upd(ll i,ll j,ll x,ll y,ll t){
	sum[i][j][t] = max(sum[i+x][j+y][t],1ll)*c[i][j]%p;
	lg[i][j][t] = (c[i][j] ? lg[i+x][j+y][t] : 0) + log(max(c[i][j],1ll));
	l[i][j][t] = c[i][j] ? l[i+x][j+y][t]+1 : 0;
}

inline void cal(double &lgg,ll i,ll j,ll lx,ll ly,ll t){
	lgg += lg[i][j][t]-lg[i+lx][j+ly][t];
}

inline void calc(ll &s,ll i,ll j,ll lx,ll ly,ll t){
	s = s*sum[i][j][t]%p*inv(sum[i+lx][j+ly][t])%p;
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i <= n;i++){
		scanf("%s",ss+1);
		for(int j=1;j <= n;j++)
			c[i][j] = ss[j]-'0';
	}
	for(ll i=1;i <= n;i++)
		for(ll j=1;j <= n;j++){
			upd(i,j,0,-1,0);
			upd(i,j,-1,-1,1);
			upd(i,j,-1,0,2);
			upd(i,j,-1,1,3);
		}
	for(ll i=n;i >= 1;i--)
		for(ll j=n;j >= 1;j--){
			upd(i,j,0,1,4);
			upd(i,j,1,1,5);
			upd(i,j,1,0,6);
			upd(i,j,1,-1,7);
		}
	for(ll i=1;i <= n;i++)
		for(ll j=1;j <= n;j++){
			ll len = N;
			for(ll t=0;t < 8;t += 2) len = min(len,l[i][j][t]);
			if(len){
				double lgg = 0;
				cal(lgg,i,j,0,-len,0);
				cal(lgg,i,j,-len,0,2);
				cal(lgg,i,j,0,len,4);
				cal(lgg,i,j,len,0,6);
				lgg -= 3*log(c[i][j]);
				if(lgg > maxn)
					maxn = lgg , ansi = i , ansj = j , ansl = len , anst = 0;
			}
			
			len = N;
			for(ll t=1;t < 8;t += 2) len = min(len,l[i][j][t]);
			if(len){
				double lgg = 0;
				cal(lgg,i,j,-len,-len,1);
				cal(lgg,i,j,-len,len,3);
				cal(lgg,i,j,len,len,5);
				cal(lgg,i,j,len,-len,7);
				lgg -= 3*log(c[i][j]);
				if(lgg > maxn)
					maxn = lgg , ansi = i , ansj = j , ansl = len , anst = 1;
			}
		}
	if(!anst){
		calc(ans,ansi,ansj,0,-ansl,0);
		calc(ans,ansi,ansj,-ansl,0,2);
		calc(ans,ansi,ansj,0,ansl,4);
		calc(ans,ansi,ansj,ansl,0,6);
	}
	else{
		calc(ans,ansi,ansj,-ansl,-ansl,1);
		calc(ans,ansi,ansj,-ansl,ansl,3);
		calc(ans,ansi,ansj,ansl,ansl,5);
		calc(ans,ansi,ansj,ansl,-ansl,7);
	}
	ans = ans*pw(inv(c[ansi][ansj]),3)%p , 
	printf("%lld\n",ans);
}