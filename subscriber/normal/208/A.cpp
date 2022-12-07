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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

string s;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> s;
	for (int i=s.size()-3;i>=0;i--)if (s.substr(i,3)=="WUB"){
		s.erase(s.begin()+i,s.begin()+i+3);
		s.insert(s.begin()+i,' ');
	}
	for (int i=s.size()-1;i>=0;i--)if (s[i]==' '&&(i==s.size()||s[i+1]==' '))s.erase(s.begin()+i);
	while (s.size()&&s[0]==' ')s.erase(s.begin());
	CC(s);
	return 0;
}