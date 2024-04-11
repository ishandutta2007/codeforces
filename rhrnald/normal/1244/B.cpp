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
string s;
void proc() {
	scanf("%d", &n);
	cin >> s;
	int l=-1,r=-1;
	for(int i=0; i<n; i++) {
		if(s[i]=='1') {l=i; break;}
	}
	for(int i=n-1; i>=0; i--) {
		if(s[i]=='1') {r=i; break;}
	}
	if(l==-1) {printf("%d\n", n); return;}

	printf("%d\n", max(n-l, r+1)*2);
}
int main(void){
	int tc; scanf("%d", &tc);
	while(tc--) proc();
}