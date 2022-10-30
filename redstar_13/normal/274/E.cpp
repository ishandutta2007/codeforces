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



#define NN 100100

#define MM 200200

vector <pii> sum[MM], dif[MM];

map <pii, int> mp;



int main(){

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

	

	int n, m, k;

	cin >> n >> m >> k;

	for(int i=0; i<k; i++){

		int x, y;

		gn(x, y);

		sum[x+y].pb(pii(x, y));

		dif[x-y+NN].pb(pii(x, y));

		mp[pii(x, y)]=1;

	}

	

	for(int i=0; i<=m+1; i++) sum[i].pb(pii(0, i)), dif[NN-i].pb(pii(0, i)), mp[pii(0, i)]=1;

	for(int i=0; i<=m+1; i++) sum[n+1+i].pb(pii(n+1, i)), dif[n+1+NN-i].pb(pii(n+1, i)), mp[pii(n+1, i)]=1;

	for(int i=1; i<=n; i++) sum[i].pb(pii(i, 0)), dif[NN+i].pb(pii(i, 0)), mp[pii(i, 0)]=1;

	for(int i=1; i<=n; i++) sum[i+m+1].pb(pii(i, m+1)), dif[i+NN-m-1].pb(pii(i, m+1)), mp[pii(i, m+1)]=1;

	

	for(int i=0; i<MM; i++){

		sort(sum[i].begin(), sum[i].end());

		sort(dif[i].begin(), dif[i].end());

	}

	

	int x, y;

	char s[3];

	

	cin >> x >> y >> s;

	int dx=s[0]=='S' ? 1 : -1;

	int dy=s[1]=='E' ? 1 : -1;

	

	vector <pii> path;

	

	int ok=0;

	int fx=dx, fy=dy;

	while(1){

		int xx, yy;

		vector <pii> :: iterator it;

		if(dx==1 && dy==1) it=lower_bound(dif[x-y+NN].begin(), dif[x-y+NN].end(), pii(x, y));

		if(dx==1 && dy==-1) it=lower_bound(sum[x+y].begin(), sum[x+y].end(), pii(x, y));

		if(dx==-1 && dy==1) it=lower_bound(sum[x+y].begin(), sum[x+y].end(), pii(x, y)), it--;

		if(dx==-1 && dy==-1) it=lower_bound(dif[x-y+NN].begin(), dif[x-y+NN].end(), pii(x, y)), it--;

		xx=it->x, yy=it->y;

		

		if(path.size()) path.pb(pii(x, y));

		path.pb(pii(xx-dx, yy-dy));

		

		if(path.size()>1 && path.back()==path[0] && dx==fx && dy==fy) break;

		

		x=xx, y=yy;

		if(mp.count(pii(xx, yy-dy))){

			if(mp.count(pii(xx-dx, yy))) dx=-dx, dy=-dy, x+=dx, y+=dy, ok=1;

			else dx=-dx, x+=dx;

		}

		else if(mp.count(pii(xx-dx, yy))) dy=-dy, y+=dy;

		else dx=-dx, dy=-dy, x+=dx, y+=dy, ok=1;

	}

	

	INT ans=0;

	for(int i=2; i<path.size(); i+=2) ans+=1+abs(path[i].x-path[i-1].x);

	

	cout << ans/(ok+1) << endl;

	

	return 0;

}