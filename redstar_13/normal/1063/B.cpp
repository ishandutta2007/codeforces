#include <bits/stdc++.h>



#define x first

#define y second

#define eps 1e-8

#define pb push_back

#define mod 1000000007

#define inf 0x3f3f3f3f

#define INF 0x3f3f3f3f3f3f3f3fLL

#define bit(x, y) (((x)>>(y))&1)

#define bctz(x) (__builtin_ctz(x))

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) (__builtin_clzll(x))

#define bctzl(x) (__builtin_ctzll(x))

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define PQ priority_queue<pii, vector<pii>, greater<pii> >



using namespace std;



typedef double DO;

typedef long long INT;

typedef pair<int, int> pii;

typedef pair<pii, int> pi3;

typedef vector<int> VI;



template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}



template<typename T> inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}

template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}

template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}

template<typename T> inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}

template<typename T> inline void println(T x) {print(x), putchar('\n');}

template<typename T> inline void printsp(T x) {print(x), putchar(' ');}

template<class T, class T1> inline void print(T x, T1 y) {printsp(x), println(y);}

template<class T, class T1, class T2> inline void print(T x, T1 y, T2 z) {printsp(x), printsp(y), println(z);}



int power(int a, int b, int m, int ans=1) {

	for (; b; b>>=1, a=(INT)a*a%m) if (b&1) ans=(INT)ans*a%m;

	return ans;

}

int dx[]={1,-1,0,0};

int dy[]={0,0,1,-1};

const int N=2222;

int n,m,x,y,xx,yy,X,Y,lft,rgt;

int dist[N][N];

char s[N][N];

queue<pii> q;

bool out(int x,int y) {return x<0 || y<0 || x>=n || y>=m || s[x][y]=='*';}



int main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

	gn(n,m);

	gn(X,Y);X--;Y--;

	gn(rgt,lft);

	for(int i=0; i<n; i++) scanf("%s",s[i]);

	for(int i=0; i<n; i++) for(int j=0; j<m; j++) dist[i][j]=inf;

	dist[X][Y]=0;

	q.push(pii(X,Y));

	while(!q.empty()){

		x=q.front().x;y=q.front().y;q.pop();

		for(int i=0; i<2; i++){

			xx=x+dx[i];yy=y+dy[i];

			if(out(xx,yy)) continue;

			if(dist[xx][yy]>dist[x][y]){

				dist[xx][yy]=dist[x][y];

				q.push(pii(xx,yy));

			}

		}

		

		for(int i=2; i<4; i++){

			xx=x+dx[i];yy=y+dy[i];

			if(out(xx,yy)) continue;

			if(dist[xx][yy]>dist[x][y]+1){

				dist[xx][yy]=dist[x][y]+1;

				q.push(pii(xx,yy));

			}

		}

	}

	int ans=0,a,b;

	for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(dist[i][j]!=inf) {

		b=(j-Y+dist[i][j])/2;

		a=(dist[i][j]-(j-Y))/2;

		ans+=(a<=rgt)&&(b<=lft);

	}

	println(ans);

	return 0;

}