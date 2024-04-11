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

const int N = 5010;
int n,m,f[N][N];
char s[N],t[N];

int main(){
	n=read(),m=read(),scanf("%s%s",s+1,t+1);
	f[0][0]=0;
	int ans=0;
	For(i,0,n){
		For(j,0,m){
			if (i<n&&j<m){
				if (s[i+1]==t[j+1]) f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+2);
			}
			if (i<n) f[i+1][j]=max(f[i+1][j],f[i][j]-1);
			if (j<m) f[i][j+1]=max(f[i][j+1],f[i][j]-1);
			ans=max(ans,f[i][j]);
		}
	}
	printf("%d\n",ans);
}