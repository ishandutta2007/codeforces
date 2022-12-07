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

long long x;

int n, d;

int a[N], b[N], u[N];
set<int> W;
set<int>::iterator it;
int e[N], k;

int magic = 400;

long long get() {
	 x = (x * 37 + 10007) % 1000000007;
	 return x;	
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> d >> x;
	for (int i = 0; i < n; i++) a[i] = i;
	for (int i = 0; i < n; i++) swap(a[i], a[get() % (i + 1)]);
	for (int i = 0; i < n; i++) b[i] = (i < d);
	for (int i = 0; i < n; i++) swap(b[i], b[get() % (i + 1)]);

	for (int i = 0; i < n; i++) u[a[i]] = i;


	for (int i = 0; i < n; i++) {
		if (b[i]) e[k++] = i;
		int ans = -1;
		W.insert(-a[i]);
		if (k < magic) {
			for (int j = 0; j < k; j++) if (a[i - e[j]] > ans) ans = a[i - e[j]];
		} else {
			for (it = W.begin(); it != W.end(); it++) if (b[i - u[-(*it)]]) {
				ans = -(*it);
				break;
			}
		}
		ans++;
		printf("%d\n", ans);
	}
	return 0;
}