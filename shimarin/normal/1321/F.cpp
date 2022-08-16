//    
#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 2e5+10;
int n,cnt,pos[N],pre[N];
char s[N];

const int base = 233, mod[2] = {1000000007, 998244353};
int p[N][2],h[N][2];

inline int Query(int k,int l,int r){
	return (h[r][k]-1ll*h[l-1][k]*p[r-l+1][k]%mod[k]+mod[k])%mod[k];
}
inline pa Get(int l,int r){
	int R=upper_bound(pos+1,pos+1+cnt,r)-pos-1;
	int L=lower_bound(pos+1,pos+1+cnt,l)-pos;
	if (L>R) return mp(0,0);
	if (L==R) return mp(r-pos[R]&1,0);
	int x=Query(0,L+1,R);
	if (r-pos[R]&1) x=(1ll*base*x+1)%mod[0];
		else x=1ll*base*x%mod[0];
	int y=Query(1,L+1,R);
	if (r-pos[R]&1) y=(1ll*base*y+1)%mod[1];
		else y=1ll*base*y%mod[1];
	return mp(x,y);
}

int main(){
	n=read(),scanf("%s",s+1);
	For(i,1,n){
		if (s[i]=='0') pos[++cnt]=i;
		pre[i]=cnt;
	}
	pos[++cnt]=n+1;
	p[0][0]=1,p[0][1]=1;
	For(i,1,n)
		For(j,0,1) p[i][j]=1ll*base*p[i-1][j]%mod[j]; 
	For(i,1,cnt) 
		For(j,0,1) h[i][j]=(1ll*h[i-1][j]*base+(pos[i]-pos[i-1]-1&1))%mod[j];
	int q=read();
	while (q--){
		int l1=read(),l2=read(),len=read();
		if (pre[l1+len-1]-pre[l1-1]!=pre[l2+len-1]-pre[l2-1]){
			puts("No");
			continue;
		}
		pa x=Get(l1,l1+len-1),y=Get(l2,l2+len-1);
		puts(x==y?"Yes":"No");
	}
}