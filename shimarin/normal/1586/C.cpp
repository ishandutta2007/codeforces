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

const int N = 1e6+10;
int n,m,pre[N];
string s[N];

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	FOR(i,0,n) cin>>s[i];
	FOR(i,1,n) For(j,2,m) if (s[i-1][j-1]=='X'&&s[i][j-2]=='X') pre[j]++;
	For(j,2,m) pre[j]+=pre[j-1];
	int q;
	cin>>q;
	For(i,1,q){
		int l,r;
		cin>>l>>r;
		cout<<(pre[r]-pre[l]?"NO":"YES")<<endl;
	}
}