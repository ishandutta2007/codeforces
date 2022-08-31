#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cerr<<i<<" ";puts("")
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

const int N = 110;
int n,a[N],c[N];
ull f[N][N*N],C[N][N];

int main(){
	n=read();
	int cnt=0;
	For(i,1,n){
		a[i]=read(),c[a[i]]++;
		cnt+=(c[a[i]]==1);
	}
	if (cnt==2) return printf("%d\n",n),0;
	f[0][0]=1;
	int s=0,S=0;
	For(i,1,100) For(j,1,c[i]){
		Dow(p,s+1,1) Dow(q,S+i,i){
			f[p][q]+=f[p-1][q-i];
		}
		s++,S+=i;
	}
	C[0][0]=1;
	For(i,1,100){
		C[i][0]=1;
		For(j,1,i) C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	int ans=0;
	For(i,1,100){
		For(j,1,c[i]) if (f[j][j*i]==C[c[i]][j]) ans=max(ans,j);
	}
	printf("%d\n",ans);
}