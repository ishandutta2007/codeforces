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
#define N 111111
using namespace std;
typedef pair<int,int> pt;

string sym = "AHIMOTUVWXY";
string s;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> s;
	int bad = 0;
	for (int i = 0; i < s.size(); i++) if (s[i] != s[s.size() - 1 - i]) bad = 1;
	for (int i = 0; i < s.size(); i++) if (sym.find(s[i]) >= sym.size()) bad = 1;
	if (bad) {
		puts("NO");
		return 0;
	} 
	puts("YES");

	return 0;
}