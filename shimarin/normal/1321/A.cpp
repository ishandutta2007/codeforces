//    
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

const int N = 110;
int n,a[N],b[N];

int main(){
	n=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) b[i]=read();
	int A=0,B=0;
	For(i,1,n){
		if (a[i]&&!b[i]) ++A;
		if (!a[i]&&b[i]) ++B;
	}
	if (A==0) return puts("-1"),0;
	++B;
	if (B%A==0) printf("%d\n",B/A);
		else printf("%d\n",B/A+1);
}