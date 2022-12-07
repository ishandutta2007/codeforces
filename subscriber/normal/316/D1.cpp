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

int n,a[11],p[11],ans,f[11];


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++)p[i] = i;
	do{
		for (int i=0;i<n;i++)f[i]=0;
		int bad = 0;
		for (int i=0;i<n;i++)if (!f[i]){
			int x = p[i];
			int s = 0;
			s += (a[i] == 1);
			while (x!= i){
				f[x] = 1;
				s += (a[x] == 1);
				x=p[x];
			}
			if (s > 2)bad = 1;
		}
		ans += 1-bad;
	}while(next_permutation(p,p+n));
	cout << ans << endl;	                          	
	return 0;
}