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

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	int n, p;
	string s, ans;
	cin >> n >> p;
	cin >> s;
	ans = s;
	for (int i = s.size() - 1; i >= 0; i--) for (char g = s[i] + 1; g < p + 'a'; g++) {
		if (i > 0 && g == s[i - 1]) continue;
		if (i > 1 && g == s[i - 2]) continue;
		ans[i] = g;
		char q1 = g;
		char q2 = 0;
		if (i != 0) q2 = s[i - 1];
		int bad = 0;
		for (int j = i + 1; j < n; j++) {
			int h = 0;
			for (char w = 'a'; w < 'a' + p; w++) if (w != q1 && w != q2) {
				h = 1;
				q2 = q1;
				q1 = w;
				ans[j] = w;
				break;
			} 
			if (!h) {
				bad = 1;
				break;
			}
		}
		if (!bad) {
			cout << ans << endl;
			return 0;
		}
	}
	puts("NO");
	return 0;
}