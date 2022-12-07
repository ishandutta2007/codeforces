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
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n,ans[3000333];

void solve(int n){
	if (n<1)return;
	int e=0,t=n;
	while (t!=1)t/=2,e++;
	for (int i=n;i>=pw(e);i--){
		ans[i]=(pw(e)-1)^(i-pw(e));
		ans[(pw(e)-1)^(i-pw(e))]=i;
	}
	int d=n-pw(e)+1;
	solve(n-d-d);

}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	long long aa=0;
	for (int i=0;i<=n;i++)aa+=i+i;
	solve(n);
	cout << aa << endl;
	for (int i=0;i<n;i++)printf("%d ",ans[i]);
	cout << ans[n] << endl;
	return 0;
}