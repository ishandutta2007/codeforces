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

int main(){
	int l=read(),r=read(),x=read(),y=read();
	int ans=0;
	if (y%x) return puts("0"),0;
	y/=x;
	int k=sqrt(y);
	For(i,1,k) if (y%i==0){
		if (__gcd(i,y/i)==1){
			int a=i*x,b=y/i*x;
			if (a>=l&&a<=r&&b>=l&&b<=r){
				++ans;
				if (a!=b) ++ans;
			}
		}
	}
	printf("%d\n",ans);
}