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

char s[1000];
inline int get(){
	int k=read();
	For(i,1,k) scanf("%s",s);
	return k;
}

int main(){
	while (1){
		printf("next 0\n");fflush(stdout);
		get();
		printf("next 0 1\n");fflush(stdout);
		if (get()==2) break;
	}
	while (1){
		printf("next 0 1 2 3 4 5 6 7 8 9\n");fflush(stdout);
		if (get()==1) break;
	}
	puts("done");
	fflush(stdout);
}