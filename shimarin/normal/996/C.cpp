#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
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
int n,k,a[5][N];

const int dx[5] = {0,-1,0,1,0};
const int dy[5] = {0,0,1,0,-1};
vector<pair<int,pa>>ans;
inline int Move(int x,int y,int z){
	if (!a[x][y]) return 0;
	int i=x+dx[z],j=y+dy[z];
	if (a[i][j]&&i!=1&&i!=4) return 0;
	ans.pb(mp(a[x][y],mp(i,j)));
	a[i][j]=a[x][y],a[x][y]=0;
	return 1;
}

int main(){
	n=read(),k=read();
	For(i,1,4) For(j,1,n) a[i][j]=read();
	int cnt=0;
	For(i,1,n) if (a[1][i]==a[2][i]&&a[2][i]){
		Move(2,i,1),cnt++;
	}
	For(i,1,n) if (a[3][i]==a[4][i]&&a[3][i]){
		Move(3,i,3),cnt++;
	}
	if (k-cnt==2*n) return puts("-1"),0;
	while (cnt<k){
		int ret=Move(2,1,3);
		For(i,2,n) Move(2,i,4);
		if (n>1) Move(3,n,1);
		if (ret) Dow(i,n-1,2) Move(3,i,2);
			else Dow(i,n-1,1) Move(3,i,2);
		For(i,1,n) if (a[1][i]==a[2][i]&&a[2][i]){
			Move(2,i,1),cnt++;
		}
		For(i,1,n) if (a[3][i]==a[4][i]&&a[3][i]){
			Move(3,i,3),cnt++;
		}
	}
	printf("%d\n",siz(ans));
	for (auto i:ans) printf("%d %d %d\n",i.fi,i.se.fi,i.se.se);
}