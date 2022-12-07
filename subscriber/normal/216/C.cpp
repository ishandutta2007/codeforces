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

int n,m,k;
vector<int>ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> k;
	if (k==1){
		int s=1;
		while (s<=n+m){
			ans.pb(s);
			s+=n-1;
		}
	}else{
		for (int i=0;i<k;i++)ans.pb(1);
		int s=n;
		while (s<=n+m){
			ans.pb(s);
			if (s!=n+m)for (int i=1;i<k;i++)ans.pb(s+1);
			s+=n;
		}
	}
	CC(ans.size());
	for (int i=0;i<ans.size();i++)cout << ans[i] << " ";
	return 0;
}