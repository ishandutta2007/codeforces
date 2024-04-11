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



const int mod=1000000007;

vector <pii> V;

int cnt[3];



int calc(int a, int b){

	return (INT)(a+b)*(b-a+1)/2%mod;

}



int dp[1111][4];



int main(){

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

	

	V.pb(pii(2, 0));

	V.pb(pii(3, 1));

	

	int n, p;

	cin >> n >> p;

	p--;

	

	if(p<=2) return puts("0"), 0;

	

	while(V.back().x<p){

		int n=V.back().x+1;

		int a=n/3;

		int b=n-n/3;

		auto ia=lower_bound(V.begin(), V.end(), pii(a, 0));

		auto ib=lower_bound(V.begin(), V.end(), pii(b, 0));

		int now=0;

		while(now==ia->y || now==ib->y) now++;

		INT m=(3LL*(ib->x+1)+1)/2;

		while(m-m/3>ib->x) m--;

		smin(m, 3LL*ia->x+2);

		smin(m, p);

		if(V.back().y==now) V.back().x=m;

		else V.pb(pii(m, now));

	}

	

	for(int i=0; i<V.size(); i++) cnt[V[i].y]=(cnt[V[i].y]+calc(p-V[i].x+1, p-(i ? V[i-1].x : 0)))%mod;

	

	dp[0][0]=1;

	for(int i=1; i<=n; i++){

		for(int j=0; j<=3; j++){

			for(int k=0; k<3; k++){

				dp[i][j^k]=(dp[i][j^k]+(INT)dp[i-1][j]*cnt[k])%mod;

			}

		}

	}

	

	cout << ((INT)dp[n][1]+dp[n][2]+dp[n][3])%mod << endl;

	

	return 0;

}