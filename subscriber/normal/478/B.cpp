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

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	int n, m;
	cin >> n >> m;
	long long ma = (n - m + 1) * 1ll * (n - m) / 2;

	int a = n / m;
	int b = a + 1;
	int cb = n % m;

	int ca = m - n % m;

	long long mi = a * 1ll * (a - 1) / 2 * ca + b * 1ll * (b - 1) / 2 * cb;
	cout << mi << " " << ma << endl;
	return 0;
}