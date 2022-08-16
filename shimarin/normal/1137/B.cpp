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

const int N = 5e5+10;
int n,m,cnt[2],fail[N];
char s[N],t[N];

int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	For(i,1,n) cnt[s[i]-'0']++;
	fail[1]=0;
	int j=0;
	For(i,2,m){
		while (j&&t[i]!=t[j+1]) j=fail[j];
		if (t[i]==t[j+1]) ++j;
		fail[i]=j;
	}
	int now=1;
	For(i,1,n){
		if (cnt[t[now]-'0']){
			printf("%c",t[now]),--cnt[t[now]-'0'];
			if (now<m) ++now;
			else if (fail[m]==0) now=1;
			else now=fail[m]+1;
		} else printf("%d",(t[now]-'0')^1);		
	}
}
/*
11011011
11011
*/