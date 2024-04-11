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
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

string s;


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> s;
	for (int d=1;d+d<=s.size();d++) {
		int t = 0;
		int q = 0;
		for (int i=0;i<d;i++)if (s[i] == s[i+d]) q++;
		for (int i=0;i + d + d <= s.size(); i++) {
			if (q == d) {
				s.erase(i,d);
				t=1;
				break;	
			}
			if (s[i] == s[i+d]) q--;
			if (i + d + d <s.size() && s[i+d] == s[i+d+d]) q++;
		}
		if (t)d--;
	}
	cout << s << endl;
	return 0;
}