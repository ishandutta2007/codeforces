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
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	string s;
	cin >> s;
	int t=0;
	for (int i=1;i<s.size();i++)if (s[i]>'Z')t=1;
	if (!t){
		for (int i=0;i<s.size();i++)if (s[i]<='Z')s[i]+='a'-'A';else s[i]-='a'-'A';
	}
	CC(s);
	return 0;
}