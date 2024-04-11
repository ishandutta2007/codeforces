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
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		sum += x;
	}
	if (sum == 0 || sum % 5 > 0) puts("-1"); else cout << sum / 5 << endl;
	return 0;
}