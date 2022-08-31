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

const int N = 55;
int n,m;
char s[N][N];
bitset<N>l[N],r[N];

int main(){
	n=read(),m=read();
	For(i,1,n){
		scanf("%s",s[i]+1);
		For(j,1,m) if (s[i][j]=='#') l[i][j]=1,r[j][i]=1;
	}
	For(i,1,n){
		int pos=0;
		For(j,1,m) if (s[i][j]=='#'){
			if (!pos) pos=j;
			if (r[j]!=r[pos]) return puts("No"),0;
		}
	}
	puts("Yes");
}