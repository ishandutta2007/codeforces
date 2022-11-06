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
int n,a,x,b;
void proc() {
	scanf("%d%d%d", &n, &a, &b);
	bool flag=false;
	for(int i=0; i<a; i++) {
		scanf("%d", &x);
		if(x==n) flag=true;
	}
	for(int i=0; i<b; i++) {
		scanf("%d", &x);
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--) proc();
}