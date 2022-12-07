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

string s[1111];
int n,o=-1,a[1111];
map<string,int>m,mm;
map<string,int>::iterator it;


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> s[i] >> a[i];
		m[s[i]]+=a[i];
	}
	for (it=m.begin();it!=m.end();it++)o=max(o,(*it).S);
	for (int i=0;i<n;i++){
		mm[s[i]]+=a[i];
		if (mm[s[i]]>=o&&m[s[i]]==o){
			CC(s[i]);
			return 0;
		}
	}
	return 0;
}