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
int n,m,a[N][N];
char s[N][N];

struct node{
	int a,b,c,d,e,f;
};
vector<node>ans;
inline void upd(int x,int y,int k){
	if (k==1){
		a[x][y]^=1,a[x][y+1]^=1,a[x+1][y+1]^=1,ans.pb((node){x,y,x,y+1,x+1,y+1});
		a[x][y]^=1,a[x+1][y]^=1,a[x+1][y+1]^=1,ans.pb((node){x,y,x+1,y,x+1,y+1});
		a[x][y]^=1,a[x][y+1]^=1,a[x+1][y]^=1,ans.pb((node){x,y,x,y+1,x+1,y});
	}
	if (k==2){
		a[x][y+1]^=1,a[x+1][y]^=1,a[x+1][y+1]^=1,ans.pb((node){x,y+1,x+1,y,x+1,y+1});
		a[x][y]^=1,a[x][y+1]^=1,a[x+1][y]^=1,ans.pb((node){x,y,x,y+1,x+1,y});
		a[x][y]^=1,a[x][y+1]^=1,a[x+1][y+1]^=1,ans.pb((node){x,y,x,y+1,x+1,y+1});
	}
	if (k==3){
		a[x][y+1]^=1,a[x+1][y]^=1,a[x+1][y+1]^=1,ans.pb((node){x,y+1,x+1,y,x+1,y+1});
		a[x][y]^=1,a[x][y+1]^=1,a[x+1][y]^=1,ans.pb((node){x,y,x,y+1,x+1,y});
		a[x][y]^=1,a[x+1][y]^=1,a[x+1][y+1]^=1,ans.pb((node){x,y,x+1,y,x+1,y+1});
	}
	if (k==4){
		a[x][y]^=1,a[x][y+1]^=1,a[x+1][y+1]^=1,ans.pb((node){x,y,x,y+1,x+1,y+1});
		a[x][y]^=1,a[x+1][y]^=1,a[x+1][y+1]^=1,ans.pb((node){x,y,x+1,y,x+1,y+1});
		a[x][y+1]^=1,a[x+1][y]^=1,a[x+1][y+1]^=1,ans.pb((node){x,y+1,x+1,y,x+1,y+1});
	}
}
inline void solve(){
	n=read(),m=read();
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,n) For(j,1,m) a[i][j]=s[i][j]-'0';
	ans.clear();
	if (s[1][1]=='1') upd(1,1,1);
	For(i,2,m) if (a[1][i]) upd(1,i-1,2);
	For(i,2,n) if (a[i][1]) upd(i-1,1,3);
	For(i,2,n)
		For(j,2,m) if (a[i][j]) upd(i-1,j-1,4);
	For(i,1,n) For(j,1,m) assert(a[i][j]==0);
	printf("%d\n",siz(ans));
	for (auto i:ans) printf("%d %d %d %d %d %d\n",i.a,i.b,i.c,i.d,i.e,i.f);
}

int main(){
	int T=read();
	while (T--) solve(); 
}