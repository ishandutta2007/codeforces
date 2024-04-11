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
#include<time.h>
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

int n,x,y,f[111111],u,uu,li;
vector<int> v[111111];
char ans[111111], o;

void rec(int x){
	f[x] = 1;
	u++;
	for (int i=0;i<v[x].size();i++) if (!f[v[x][i]] && !ans[v[x][i]]) {
		rec(v[x][i]);
	}
}

int pec(int x){
	if (f[x] == 2 || ans[x])return 0;
	f[x] = 2;
	int r = 1;
	for (int i=0;i<v[x].size();i++) r += pec(v[x][i]);
	if (li == -1 && r+r>=u) li = x;
	return r;
}

bool solve() {
	for (int i=0;i<n;i++)ans [i] = 0;
	for (o = 'A'; o<='Z'; o++) {
		for (int i=0;i<n;i++) f[i] = 0;
		for (int i=0;i<n;i++) if (!ans[i] && !f[i]) {
			li = -1;
			u = uu = 0;
			rec(i);
			pec(i);
			ans[li] = o;
		}
	}
	for (int i=0;i<n;i++)if (!ans[i]) return 0;
	return 1;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	srand((int)time(NULL));
	cin >> n;
	for (int i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}              
	for(;;){
		if (solve())break;
	}
	for (int i=0;i<n-1;i++)printf("%c ", ans[i]);
	cout << ans[n-1] << endl;
	return 0;
}