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
int n,m,x,y;
int cnt[N];
int main(void){
	scanf("%d", &n);
	for(int i=1; i<n; i++) {scanf("%d%d", &x, &y); cnt[x]++, cnt[y]++;}
	for(int i=1; i<=n; i++) if(cnt[i]==2) {printf("NO"); return 0;}
	printf("YES");
}