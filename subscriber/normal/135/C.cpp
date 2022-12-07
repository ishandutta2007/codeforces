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

string s;
int n,xx,yy,a,b,c,f[5];


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> s;
	n=s.size();
	for (int i=0;i<n;i++)if (s[i]=='0')a++;else if (s[i]=='1')b++;else c++;
	xx=(n-2+1)/2;
	yy=(n-2)/2;
	for (int i=0;i<=c;i++){
		int x=a+i-yy;
		int y=b+c-i-xx;
		if (x>y)f[0]=1;
		if (x<y)f[3]=1;
		if (x==y){
			if (s[n-1]=='1'||(s[n-1]=='?'&&i<c))f[1]=1;
			if (s[n-1]=='0'||(s[n-1]=='?'&&i))f[2]=1;
		}
	}
	if (f[0])puts("00");
	if (f[1])puts("01");
	if (f[2])puts("10");
	if (f[3])puts("11");
	return 0;
}