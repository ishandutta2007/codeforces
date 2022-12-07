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

string h[3] = {
"qwertyuiop",
"asdfghjkl;",
"zxcvbnm,./"
};

char go(char ch, char x) {
	for (int i = 0; i < 3; i++) for (int j = 0; j < h[i].size(); j++) if (h[i][j] == x) {
		if (ch == 'R') return h[i][j - 1];
		return h[i][j + 1];
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	char ch;
	string s;

	cin >> ch >> s;
	for (int i = 0; i < s.size(); i++) {
		s[i] = go(ch, s[i]);
	}
	cout << s << endl;
	return 0;
}