#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n, k;
vector<int> v[222000];
vector<pt> ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v[x].pb(i);
	}
	if (v[0].size() != 1) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < 100111; i++) {
		if (v[i].size() * 1ll * k < v[i + 1].size()) {
			puts("-1");
			return 0;
		}
		for (int j = 0; j < v[i].size(); j++) 
		for (long long l = j * 1ll * k; l < min((long long)v[i + 1].size(), (j + 1) * 1ll * k); l++) {
			ans.pb(mp(v[i][j], v[i + 1][l]));
		}
		if (i == 0) k--;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].F + 1, ans[i].S + 1);

	return 0;
}