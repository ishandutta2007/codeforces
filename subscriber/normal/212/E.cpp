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

int x,y,k,h,a[5555],f[5555],s[5555],o[5555],n;
vector<int>v[5555],ans;

void rec(int x){
	s[x]=1;
	for (int i=0;i<v[x].size();i++)if (!s[v[x][i]]){
		rec(v[x][i]);
		s[x]+=s[v[x][i]];
	}
}


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=1;i<n;i++){
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	rec(1);
	for (int i=1;i<=n;i++){
		k=0;
		h=0;
		for (int j=0;j<v[i].size();j++)if (s[v[i][j]]<s[i]){
			a[k++]=s[v[i][j]],h+=a[k-1];
		}
		a[k++]=n-1-h;
		m0(f);
		f[0]=1;
		for (int j=0;j<k;j++)for (int l=n-a[j];l>=0;l--)if (f[l])f[l+a[j]]=1;
		for (int j=1;j<n-1;j++)if (f[j])o[j]=1;
	}
	for (int j=1;j<n-1;j++)if (o[j])ans.pb(j);
	CC(ans.size());
	for (int i=0;i<ans.size();i++)cout << ans[i] << " " << n-1-ans[i] << endl;
	return 0;
}