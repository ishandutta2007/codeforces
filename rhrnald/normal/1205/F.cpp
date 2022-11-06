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

const int N = 101;
int n,m;

pii dp[101][5100];
pii Z={0,0};

void find(int x, int y, vector<int> &v) {
	if(x==1 && y==1) {v.push_back(1); return;}
	if(y==x*(x+1)/2) {
		for(int i=1; i<=x; i++) v.push_back(i);
		return;
	}
	if(y==x+1) {
		for(int i=2; i<=x; i+=2) v.push_back(i);
		v.push_back(1);
		int t=sz(v);
		for(int i=3; i<=x; i+=2) v.push_back(i);
		reverse(v.begin()+t, v.end());
		return;
	}
	vector<int> t2;
	int x1=dp[x][y].first;
	int y1=dp[x][y].second;
	int x2=x-x1+1;
	int y2=y-y1+1;
	find(x1, y1, v);
	find(x2, y2, t2);
	int P=t2[0];
	for(int i=0; i<sz(v); i++) v[i]+=P-1;
	for(int i=1; i<sz(t2); i++) {
		if(t2[i]<P) v.push_back(t2[i]);
		else v.push_back(t2[i]+x1-1);
	}
	if( (v[0]<v[x1-1] && v[0]<v[x1]) || (v[0]>v[x1-1] && v[0]>v[x1]) ) reverse(v.begin(), v.begin()+x1);
}
int main(void){
	dp[1][1]={1,1};
	for(int i=4; i<=100; i++) dp[i][i+1]={1,1};
	for(int i=2; i<=100; i++) dp[i][i*(i+1)/2]={1,1};
	for(int i=2; i<=100; i++) {
		for(int j=2; j<=i; j++) {
			if(i+j>101) break;
			for(int ii=i+1; ii<=i*(i+1)/2; ii++) {
				if(dp[i][ii]==Z) continue;
				for(int jj=j+1; jj<=j*(j+1)/2; jj++) {
					if(dp[j][jj]==Z) continue;
					dp[i+j-1][ii+jj-1]={i,ii};
				}
			}
		}
	}

	scanf("%d", &n);
	while(n--) {
		int x,y;
		scanf("%d%d", &x, &y);
		if(dp[x][y]==Z) {printf("NO\n"); continue;}
		
		printf("YES\n");
		vector<int> v;
		find(x,y,v);
		for(int e : v) printf("%d ", e); printf("\n");
	}
}