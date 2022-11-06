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
deque<pii> v;
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) v.push_back({i,j});
	
	bool t=0;
	while(!v.empty()) {
		pii x;
		if(t) x=v.back(), v.pop_back();
		else x=v.front(), v.pop_front();
		printf("%d %d\n", x.first, x.second);
		t=!t;
	}
}