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
int x[N];
vector<pii> v;
int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", x+i);
		if(x[i]<0) x[i]=-x[i]-1;
		v.push_back({x[i], i});
	}
	sort(all(v));
	int cnt=0;
	
	for(int i=0; i<n-1; i+=2) {
		v[i].first=-1-v[i].first;
		v[i+1].first=-1-v[i+1].first;
	}
	for(int i=0;i<n;i++)x[v[i].second]=v[i].first;
	for(int i=0;i<n;i++) printf("%d ", x[i]);
}