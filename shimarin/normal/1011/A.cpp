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

const int N = 51;
int n,k,f[N][N];
char s[N];

int main(){
	n=read(),k=read(),scanf("%s",s+1);
	sort(s+1,s+1+n);
	int ans=s[1]-'a'+1,now=s[1];
	int tot=1;
	if (k==1) return printf("%d\n",ans),0;
	For(i,2,n){
		if (s[i]-'a'-1>now-'a'){
			now=s[i],ans+=s[i]-'a'+1,++tot;
			if (tot==k) return printf("%d\n",ans),0;
		}
	}
	puts("-1");
}