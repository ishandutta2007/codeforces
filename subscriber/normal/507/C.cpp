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
#define buli(x) __builtin_popcountll(x)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int h;
long long n;

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> h >> n;
	n--;
	long long pos = 0;
	int o = 0;
	for (int i = h - 1; i >= 0; i--) {
		int b = 0;
		if (n & pw(i)) b = 1;

		if (b ^ o) {
			pos += pw(i);
		} else o ^= 1;
	}
	long long ans = 0;
	for (int i = 0; i< h ; i++) {
		ans += pos + 1;
		pos /= 2;
	}
	cout << ans << endl;
	return 0;
}