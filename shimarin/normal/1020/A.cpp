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

int n,h,a,b,q;

int main(){
	n=read(),h=read(),a=read(),b=read(),q=read();
	For(i,1,q){
		int a1=read(),b1=read(),a2=read(),b2=read();
		if (a1==a2){
			printf("%d\n",abs(b1-b2));
			continue;
		}
		if (b1>b2) swap(a1,a2),swap(b1,b2);
		if (b2<=a){
			printf("%d\n",abs(a1-a2)+a-b1+a-b2);
		} else if (b1>=b){
			printf("%d\n",abs(a1-a2)+b1-b+b2-b);
		} else {
			printf("%d\n",abs(a1-a2)+b2-b1);
		}
	}
}