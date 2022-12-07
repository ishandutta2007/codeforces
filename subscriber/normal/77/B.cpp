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

long double ans;
int a,b,t;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> t;
	cout.precision(6);
	while (t--){
		scanf("%d%d",&a,&b);
		if (!b){
			puts("1");
			continue;
		}
		if (!a){
			puts("0.5");
			continue;
		}
		ans=0.5;
		int x=min(a,b*4);
		ans+=x/16./b*x/a;
		ans+=(a-x)/2./a;
		cout<< fixed << ans << endl;
	}
	return 0;
}