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

int n,x[333],y[333],e[333],ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> x[i] >> y[i];
	for (int i=0;i<n;i++)for (int j=0;j<n;j++){
		if (x[i]==x[j]&&y[i]<y[j])e[i]|=1;
		if (x[i]==x[j]&&y[i]>y[j])e[i]|=2;
		if (x[i]<x[j]&&y[i]==y[j])e[i]|=4;
		if (x[i]>x[j]&&y[i]==y[j])e[i]|=8;
	}
	for (int i=0;i<n;i++)if (e[i]==15)ans++;
	CC(ans);
	return 0;
}