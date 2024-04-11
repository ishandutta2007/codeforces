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
int a[N], b[N];
set<int> S;

int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", a+i), S.insert(a[i]);
	scanf("%d", &m);
	for(int i=0; i<m; i++) scanf("%d", b+i), S.insert(b[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			if(S.find(a[i]+b[j]) == S.end()) {
				printf("%d %d", a[i], b[j]);
				return 0;
			}
		}
}