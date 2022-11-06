#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 1000001;
int n,m;
int x,y;

vector<int> v[N];
vector<int> idx;

int num=0;
vector<int> tp[3];
map<int,int> M;

int ans[N];
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1; i<=n; i++) sort(all(v[i]));

	tp[0]=v[1]; num=1; ans[1]=0;
	for(int i=2; i<=n; i++) {
		bool flag=false;
		for(int j=0; j<num; j++) {
			if(v[i]==tp[j]) {ans[i]=j, flag=true; break;}
		}
		if(flag) continue;
		if(num==3) {printf("-1"); return 0;}
		tp[num]=v[i]; ans[i]=num; num++;
	}

	if(num<3) {printf("-1"); return 0;}
	int cnt[3]={0,0,0};
	for(int i=1; i<=n; i++) cnt[ans[i]]++;
	for(int i=0; i<3; i++) if(cnt[i]+sz(tp[i]) != n) {printf("-1"); return 0;}
	for(int i=1; i<=n; i++) printf("%d ", ans[i]+1);
}