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
int n,m,a,b,c;
void proc() {
	scanf("%d%d%d", &a, &b, &c);

	int ans=0;
	for(int i=0; i<=a; i++) {
		if(b<i+i) break;
		ans=max(ans,i+min(b-i-i, c/2));
	}
	printf("%d\n", ans*3);
}
int main(void){
	int tc; scanf("%d", &tc);
	while(tc--) proc();
}