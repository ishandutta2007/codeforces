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

const int N = 1e5+10;
int n,a[N];

int main(){
	n=read();
	int x=0;
	For(i,1,n) a[i]=read(),x^=a[i];
	if (n%2==0){
		n--;
		if (x) return puts("NO"),0;
	}
	puts("YES"),printf("%d\n",n-2);
	for (int i=1;i+2<=n;i+=2) printf("%d %d %d\n",i,i+1,i+2);
	for (int i=1;i+3<=n;i+=2) printf("%d %d %d\n",i,i+1,n);
}