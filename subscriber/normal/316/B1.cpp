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

int n,k,p[111111],q[111111],f[111111],l[111111];
vector<int>e;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	k--;
	for (int i=0;i<n;i++){
		cin >> p[i];
		p[i]--;
		if (p[i] != -1 ) l[p[i]]=1;
	}
	for (int i=0;i<n;i++)if (!f[i] && !l[i]){
		int s=0;
		int x=i;
		int g = 0;
		while (x!= -1){
			if (x == k)g = 1;
			s++;
			f[x] = 1;
			x = p[x];
		}
		if (g)continue;
		e.pb(s);
	}
	int s=0;
	while (k != -1){
		s++;
		k = p[k];
	}
	q[0] = 1;
	for (int i=0;i<e.size();i++) {
		for (int j=n;j>=0;j--)q[j + e[i]] |= q[j];
	}
	for (int i=0;i<=n;i++)if (q[i]) printf("%d\n",i + s);
	return 0;
}