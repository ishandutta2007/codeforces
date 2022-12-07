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
#define sz size
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << x << endl
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long ull;


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		long long s=n-4ll*i;
		if (s<0||s%3)continue;
		int o=s/3;
		if (o>i)continue;
		for (int j=0;j<i-o;j++)putchar('4');
		for (int j=0;j<o;j++)putchar('7');
		return 0;

	}
	puts("-1");
	return 0;
}