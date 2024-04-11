#include<bits/stdc++.h>
#define For(i,x,y) for (int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (int i=(x);i<(y);i++)
#define Dow(i,x,y) for (int i=(x);i>=(y);i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a)/2)
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
int n,m,nxt[N][30],cnt[50];
char s[N];

int v[N];
inline int work(int l,int r,int p){
	int ret=0,cnt=0;
	for (int x=nxt[l][p];;x=nxt[x+1][p]){
		v[++cnt]=x;
		if (!(x+m<=r)) break;
	}
	int now=l-1;
	For(i,1,cnt){
		if (v[i]-now-1>=m) now=v[i-1],++ret;
	}
	if (r-now>=m) ++ret;
	return ret;
}

int main(){
	m=read(),scanf("%s",s+1);
	n=strlen(s+1);
	Dow(i,n,1){
		For(j,0,25) nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i]-'a']=i;
		cnt[s[i]-'a']++;
	}
	int p=-1;
	For(i,0,25){
		int las=0,fl=1;
		For(j,1,n){
			if (s[j]-'a'<=i){
				if (j-las>m) fl=0;
				las=j;
			}
		}
		fl&=(las+m>n);
		if (!fl) continue;
		p=i;
		break; 
	}
	int las=0,tot=0;
	For(j,1,n){
		if (s[j]-'a'<=p-1){
			if (j-las>m) tot+=work(las+1,j-1,p);
			las=j;
		}
	}
	if (las+m<=n) tot+=work(las+1,n,p);
	For(i,0,p-1){
		For(j,1,cnt[i]) printf("%c",i+'a');
	}
	For(i,1,tot) printf("%c",p+'a');
}