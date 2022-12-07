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
#define mp make_pair
#define pb push_back
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n, a[1000111],p[1000111], ans,e[1000111], k;

int solve(int l,int r,int d) {
	if (l > r)return 0;
	if (l==r) {
		if (d) return 1;
		return 0;
	}
	int x = l;
	int s = 1;
	int q = 0;
	for(;;) {
		int y = p[x];
		if (y == -1 || y > r) {
			s = max(s, solve(x + 1, r, 1));
			q = max(q, solve(x + 1, r, 1));
			break;
		}
		s = max(s, solve(x + 1, y - 1, 1));
		q = max(q, solve(x + 1, y - 1, 1));
		s++;
		x = y;
	}
	if (!d)return q;
	return s;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]), p[i] = -1;
	for (int i=0;i<n;i++) {
		while (k > 0 && a[e[k - 1]] < a[i]) {
			p[e[k - 1]] = i;
			k--;
		}
		e[k++] = i;
	}
	cout << solve(0,n-1,0) << endl;
	return 0;
}