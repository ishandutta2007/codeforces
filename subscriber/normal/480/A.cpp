#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int n;
pair<int, int> q[N];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d%d", &q[i].F, &q[i].S);
	sort(q, q + n);
	int ma = -1;
	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && q[i].F == q[j].F) j++;

		int t = -1;

		for (int k = i; k < j; k++) {
			if (q[k].S < ma) {
				t = max(t, q[k].F);
			} else {
				t = max(t, q[k].S);
			}
		}

		ma = max(ma, t);

		i = j;
	}
	cout << ma << endl;
	return 0;
}