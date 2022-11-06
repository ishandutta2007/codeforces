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
int n,m,x;
int cnt[N];
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {scanf("%d", &x); cnt[x]++;}

	int ans=0,half=0;
	for(int i=1; i<=m; i++) {
		ans+=cnt[i]-(cnt[i]&1);
		half+=cnt[i]&1;
	}
	ans+=(half+1)/2;
	cout << ans;
}