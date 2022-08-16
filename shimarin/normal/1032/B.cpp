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
int n;
char s[N];

int main(){
	scanf("%s",s+1),n=strlen(s+1);
	For(i,1,5){
		int j=(n+(i-1))/i;
		if (j>20) continue;
		int k=i*j-n;
		printf("%d %d\n",i,j);
		int now=1;
		For(l,1,i-k){
			For(p,1,j) printf("%c",s[now]),++now;
			puts("");
		}
		For(l,1,k){
			FOR(p,1,j) printf("%c",s[now]),++now;
			puts("*");
		}
		return 0;
	}
}