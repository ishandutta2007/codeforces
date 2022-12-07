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
#define N 111111
using namespace std;
typedef pair<int,int> pt;

int n, k;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> k;
	if (k + k >= n) {
		puts("-1");
		return 0;
	}
	cout << n * k << endl;
	for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) printf("%d %d\n", i + 1, (i + j + 1) % n + 1);
	return 0;
}