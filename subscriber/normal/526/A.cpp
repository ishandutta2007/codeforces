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

int n;
string s;

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> s;
	for (int d = 1; d <= s.size(); d++) {
		for (int i = 0; i < s.size(); i++) if (s[i] == '*') {
			int ok = 1;
			int x = i;
			for (int j = 0; j < 4; j++) {
				x += d;
				if (x >= s.size() || s[x] == '.') {
					ok = 0;
					break;
				}
			}
			if (ok) {
				puts("yes");
				return 0;
			}

		}
	}
	puts("no");
	return 0;
}