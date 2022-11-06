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
string s;
int n,m;
int x[N];
void proc() {
	scanf("%d%d", &n, &m);
}
int a,b;
vector<int> ans;
void solve(int t) {
	for(int i=0; i<n; i++) {
		if(x[i]==t) continue;
		else ans.push_back(i+1), x[i+1]=!x[i+1];
	}
}

int main(void){
	scanf("%d", &n);
	cin >> s;
	for(int i=0; i<n; i++) {
		x[i]=(s[i]=='W');
		if(s[i]=='B') a++;
		else b++;
	}
	if((a&1)==0) {
		solve(1);
	}else if((b&1)==0) {
		solve(0);
	}else {
		printf("-1");
		return 0;
	}
	printf("%d\n", sz(ans));
	for(int e : ans) printf("%d ", e);

}