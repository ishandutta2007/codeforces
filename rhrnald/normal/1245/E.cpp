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

int x[10][10];
int loc[10][10];

vector<pii> v;
double ans[100];
int main(void){
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++) {
			scanf("%d", x[i]+j);
		}
	

	for(int i=0; i<10; i++) {
		if(i&1) {
			for(int j=9; j>=0; j--) v.push_back({i,j});
		} else {
			for(int j=0; j<10; j++) v.push_back({i,j});
		}
	}
	
	for(int i=0; i<100; i++) loc[v[i].first][v[i].second]=i;

	for(int i=1; i<100; i++) {
		int t=0;
		for(int k=1; k<=6; k++) {
			if(i<k) {t++; continue;}
			pii nxt=v[i-k];
			double t=ans[loc[nxt.first][nxt.second]];
			if(x[nxt.first][nxt.second]) {
				nxt.first-=x[nxt.first][nxt.second];
				t=min(t, ans[loc[nxt.first][nxt.second]]);
			}
			ans[i]+=(t+1)/6.0;
		}
		ans[i]=(ans[i]+t/6.0)*6/(6-t);
	}
	printf("%.10lf", ans[99]);
}