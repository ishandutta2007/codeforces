#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<complex>
#include<utility>

#define X first
#define Y second
#define REP_0(i,n) for(int i=0;i<(n);++i)
#define REP_1(i,n) for(int i=1;i<=(n);++i)
#define REP_2(i,a,b) for(int i=(a);i<(b);++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n) for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n) for(int i=(n);0<i;--i)
#define DOW_2(i,a,b) for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b) for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b) for(typeof((b).begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof((b).rbegin()) a=(b).rbegin();a!=(b).rend();++a)
#define PB push_back
#define PF push_front
#define MP make_pair
#define IS insert
#define ES erase
#define IT iterator
#define RI reserve_iterator
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define ALL(x) x.begin(),x.end()

#define PI 3.1415926535897932384626433832795
#define EXP 2.7182818284590452353602874713527

using namespace std;

typedef long long LL;
typedef long double LD;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef pair<int,PII> PIII;
typedef pair<LD,int> PLDI;
typedef vector<PII> VII;

template<class T>
T Mul(T x,T y,T P){
	T F1=0;
	while(y)
	{
		if(y&1)
		{
			F1+=x;
			if(F1<0||F1>=P)F1-=P;
		}
		x<<=1;
		if(x<0||x>=P)x-=P;
		y>>=1;
	}
	return F1;
}

template<class T>
T Pow(T x,T y,T P){
	T F1=1;x%=P;
	while(y)
	{
		if(y&1)
		{
			F1=Mul(F1,x,P);
		}
		x=Mul(x,x,P);
		y>>=1;
	}
	return F1;
}

template<class T>
T Gcd(T x,T y){
	if(y==0)return x;
	T z;
	while(z=x%y){
		x=y,y=z;
	}
	return y;
}

template<class T>
void UpdateMin(T &x,T y){
	if(y<x)
	{
		x=y;
	}
}

template<class T>
void UpdateMax(T &x,T y){
	if(x<y)
	{
		x=y;
	}
}

template<class T>
T Sqr(const T x){
	return x*x;
}

template<class T>
T Abs(const T x){
	return x<0?-x:x;
}

#define MaxBuffer 20000000
class ReadBuffer{
	private:
	char buff[MaxBuffer];
	char *buf;
	public:
	void init(int size=MaxBuffer)
	{
		fread(buff,1,size,stdin);
		buf=buff;
	}
	template<class T>
	bool readInteger(T &x)
	{
		x=0;
		while(*buf&&isspace(*buf)) ++buf;
		if(*buf==0) return false;
		static bool flag;
		flag=0;
		if(*buf=='-') flag=true;
		else x=*buf-'0';
		while(isdigit(*++buf)) x=x*10+*buf-'0';
		if(flag) x=-x;
		return true;
	}
	template<class T>
	bool readFloat(T &x)
	{
		long double nowpos=0.1;
		x=0;
		while(*buf&&isspace(*buf)) ++buf;
		if(*buf==0) return false;
		static bool flag,decimal;
		decimal=flag=0;
		if(*buf=='-') flag=true,++buf;
		else if(*buf=='.') decimal=true;
		while(isdigit(*buf)||*buf=='.')
		{
			if(*buf=='.') decimal=true;
			else
			{
				if(decimal)
				{
					x+=nowpos*(*buf-'0');
					nowpos*=0.1;
				}
				else
				{
					x=x*10+*buf-'0';
				}
			}
			++buf;
		}
		return true;
	}
	bool readChar(char c)
	{
		if(*buf==0) return 0;
		return c=*buf++,1;
	}
	bool readString(char *s)
	{
		while(*buf&&isspace(*buf)) ++buf;
		if(!*buf) return false;
		while(!isspace(*buf)) *s++=*buf++;
		*s++=0;
		return true;
	}
	int countSpacetonext(){
		int total=0;
		while(*buf&&*buf==' ') ++total,++buf;
		return total;
	}
	bool splitBycharactor(char *s,char Split='\n'){
		while(*buf&&*buf!=Split) *s++=*buf++;
		*s++=0;
		return *buf!=0;
	}
};

struct EDGE{
	int T;EDGE *Nxt;
};
vector<int> V[2][200101],ans;
int edge[2][200101][2];
int depth[2][200101];
int deep[2][200101];
int fa[2][18][200101];
int l[2][200101];
int r[2][200101];
int lt[2][524290];
bool removed[2][200101];
stack<int> deal[2];
int cmptmp;
inline bool cmp(int x,int y){
	return deep[cmptmp][x]>deep[cmptmp][y];
}
stack<int> dfs;
bool in[200101];
inline void insert(int x,int pos,int lt[]){
	pos+=262144;
	lt[pos]=x;
	while(pos>>=1){
		lt[pos]=cmp(lt[pos<<1],lt[pos<<1|1])?lt[pos<<1|1]:lt[pos<<1];
	}
}
inline int query(int x,int y,int lt[]){
	int ans=0;
	x+=262143,y+=262145;
	while(x^y^1){
		if(~x&1) ans=cmp(ans,lt[x^1])?lt[x^1]:ans;
		if(y&1)ans=cmp(ans,lt[y^1])?lt[y^1]:ans;
		x>>=1,y>>=1;
	}
	return ans;
}
const char s[2][20]={"Blue","Red"};
int n;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d",&n);
	fa[0][0][1]=fa[1][0][1]=0;
	for(int i=1;i<n;++i){
		int x;
		scanf("%d",&x);
		fa[0][0][i+1]=x;
		V[1][i+1].push_back(i);
		V[1][x].push_back(i);
		edge[1][i][0]=x,edge[1][i][1]=i+1;
	}
	for(int i=1;i<n;++i){
		int x;
		scanf("%d",&x);
		fa[1][0][i+1]=x;
		V[0][i+1].push_back(i);
		V[0][x].push_back(i);
		edge[0][i][0]=x,edge[0][i][1]=i+1;
	}
	for(int k=0;k<2;++k){
		for(int i=1;i<18;++i){
			for(int j=1;j<=n;++j){
				fa[k][i][j]=fa[k][i-1][fa[k][i-1][j]];
			}
		}
	}
	for(int k=0;k<2;++k){
		memset(in,0,sizeof(in));
		in[1]=1;
		dfs.push(1);
		int dfn=0;
		while(!dfs.empty()){
			int x=dfs.top();
			dfs.pop();
			if(x<0){
				r[k][-x]=dfn;
				continue;
			}
			dfs.push(-x);
			l[k][x]=++dfn;
			for(int i=0;i<int(V[k^1][x].size());++i){
				int y=V[k^1][x][i];
				int z=edge[k^1][y][1]^edge[k^1][y][0]^x;
				if(!in[z]){
					in[z]=1;
					depth[k][z]=depth[k][x]+1;
					dfs.push(z);
				}
			}
		}
	}
	for(int k=0;k<2;++k)
	{
		deep[k][0]=n+1;
		for(int i=1;i<=n;++i){
			int x=edge[k][i][0],y=edge[k][i][1];
			if(depth[k][x]>depth[k][y]) swap(x,y);
			for(int j=17;j>=0;--j){
				if((1<<j)&(depth[k][y]-depth[k][x])){
					y=fa[k][j][y];
				}
			}
			if(x==y) deep[k][i]=depth[k][x];
			else{
				for(int j=17;j>=0;--j){
					if((fa[k][j][y]!=fa[k][j][x])){
						y=fa[k][j][y];
						x=fa[k][j][x];
					}
				}
				deep[k][i]=depth[k][x]-1;
			}
		}
	}
	for(int k=0;k<2;++k){
		cmptmp=k;
		REP_1(i,n) sort(V[k][i].begin(),V[k][i].end(),cmp);
		REP_1(i,n) if(V[k][i].size()){
			insert(*(V[k][i].end()-1),l[k][i],lt[k]);
		}
	}
	{
		int G;
		scanf("%d",&G);
		deal[0].push(G);
		removed[1][G]=1;
	}
	int n0=0,n1=1;
	while(!deal[n0].empty()){
		cmptmp=n0;
		ans.clear();
		while(!deal[n0].empty()){
			int x=deal[n0].top(),y;
			deal[n0].pop();
			ans.push_back(x);
			++x;
			while(deep[n0][y=query(l[n0][x],r[n0][x],lt[n0])]<depth[n0][x]){
				if(!removed[n0][y]){
					removed[n0][y]=1;
					deal[n1].push(y);
				}
				for(int i=0;i<2;++i){
					int z=edge[n0][y][i];
					if(V[n0][z].size()&&removed[n0][*(V[n0][z].end()-1)]){
						while(V[n0][z].size()&&removed[n0][*(V[n0][z].end()-1)]){
							V[n0][z].pop_back();
						}
						if(V[n0][z].size()){
							insert(*(V[n0][z].end()-1),l[n0][z],lt[n0]);
						}
						else{
							insert(0,l[n0][z],lt[n0]);
						}
					}
				}
			}
		}
		sort(ans.begin(),ans.end());
		printf("%s\n",s[n0]);
		REP_0(i,int(ans.size())){
			printf("%d%c",ans[i],i==int(ans.size())-1?'\n':' ');
		}
		n0^=1,n1^=1;
	}
	return 0;
}