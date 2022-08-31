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

const int N = 1<<18|3;
int h,n,a[N],p[N];

inline void Answer(int x){
	printf("! %d\n",x),fflush(stdout);
	exit(0);
}
inline int Query(int x,int y,int z){
	printf("? %d %d %d\n",x,y,z),fflush(stdout);
	return read();
}

inline int R(int l,int r){
	int tmp=rand()<<15^rand();
	return l+tmp%(r-l+1);
}

int main(){
	h=read(),n=(1<<h)-1;
	For(i,1,420){
		int x=R(1,n),y=R(1,n),z=R(1,n);
		while (x==y||y==z||x==z) x=R(1,n),y=R(1,n),z=R(1,n);
		a[Query(x,y,z)]++;
	}
	For(i,1,n) p[i]=i;
	sort(p+1,p+1+n,[](int x,int y){
		return a[x]>a[y];
	});
	int x=p[1],y=p[2];
	For(i,1,n) if (i!=x&&i!=y&&Query(x,y,i)==i) Answer(i);
}