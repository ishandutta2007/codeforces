#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

const int NN = 2000111;
int n;
int ans,tot;
int cnt[NN], c[NN];
pii p[NN];

bool cmp(pii u, pii v) {
	return u.y<v.y;
}

INT sum;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	cin>>n;
	for (int i=0; i<n; i++) 
		scanf("%d%d", &p[i].x, &p[i].y);
	sort(p, p+n);
	for (int i=0; i<n;)  {
		int j = i;
		while ( p[i].x == p[j].x && p[i].y == p[j].y && j<n ) c[tot]++, j++;
		tot++, i=j;
	}
	INT t=0;
	for (int i=0; i<tot; i++) t+=(INT)c[i] * (c[i] - 1);
	t/=2;
	for (int i=0; i<n;)  {
		int j=i;
		while (p[i].x == p[j].x && j<n ) cnt[ans]++,j++;
		i=j; ans++;
	}
	sort(p,p+n, cmp);
	for (int i=0; i<n;)  {
		int j=i;
		while (p[i].y == p[j].y && j<n ) cnt[ans]++,j++;
		i=j; ans++;
	}
	for (int i=0; i<ans ;i ++ ) sum+=(INT)cnt[i]*(cnt[i]-1);
	sum/=2;
	sum-=t;
	cout<<sum<<endl;
	return 0;
}