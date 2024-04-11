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
int vst[N];
bool inq[N];
int cur=1;
int num=0;
vector<int> ans;
int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", x+i);
	ans.push_back(-1);
	for(int i=0; i<n; i++) {
		if(x[i]>0) {
			if(vst[x[i]]==cur) {
				printf("-1");
				return 0;
			}
			vst[x[i]]=cur;
			inq[x[i]]=cur;
			num++;
		}
		if(x[i]<0) {
			int c=-x[i];
			if(!inq[c]) {
				printf("-1");
				return 0;
			}
			inq[c]=false;
			num--;
			if(!num) {
				ans.push_back(i);
				cur++;
			}
		}
	}
	if(num) {
		printf("-1");
		return 0;
	}
	printf("%d\n", sz(ans)-1);
	for(int i=1; i<sz(ans); i++) {
		printf("%d ", ans[i]-ans[i-1]);
	}
}