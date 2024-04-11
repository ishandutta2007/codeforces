#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
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

const int N = 60, A = 30, B = 340;
int n,a[N],f[N][A*2+10][B*2+10];
char s[N];

inline void upd(int &x,int y){
	x=min(x,y);
}

int main(){
	scanf("%s",s+1),n=strlen(s+1);
	For(i,1,n) a[i+5]=s[i]-'0';
	n+=5,fil(f,30);
	f[0][A][B]=0;
	FOR(i,0,n) For(j,-A,A) For(k,-6*i,6*i) if (f[i][j+A][k+B]<10000000){
		For(l,-6,6){
			int tmp=j*10+k+l-a[i+1];
			if (tmp>=-A&&tmp<=A) upd(f[i+1][tmp+A][k+l+B],f[i][j+A][k+B]+(n-i)*abs(l));
		}
	}
	int ans=1e9;
	For(i,-B,B) upd(ans,f[n][A][i+B]);
	printf("%d\n",ans);
}