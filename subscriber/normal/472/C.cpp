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
string a[N], b[N];
int p[N];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		p[i] = x - 1;
	}		
	for (int i = 0; i < n; i++) if (a[i] > b[i]) swap(a[i], b[i]);
	string mi = a[p[0]];

	for (int i = 1; i < n; i++) {
		if (a[p[i]] > mi) {
			mi = a[p[i]];
		} else {
			if (b[p[i]] > mi) {
				mi = b[p[i]];
			} else {
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	return 0;
}