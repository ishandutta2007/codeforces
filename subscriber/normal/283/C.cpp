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

int n,k,w,kk,h[655],x,y,q=0,ff[333][111111];
long long a[655],e[655],b[655],mins=0,t;
vector<int>v[655];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k>> t;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<k;i++){
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		h[y]++;
	}
	for (int i=0;i<n;i++)if (!h[i]){
		q++;
		w=1;
		e[0]=a[i];
		int x=i;
		for(;;){
			if (v[x].empty())break;
			q++;
			x=v[x][0];
			e[w++]=a[x];
		}
		for (int j=0;j<w;j++)mins+=e[j]*1ll*(w-j-1);
		for (int j=0;j<w;j++){
			b[kk++]=e[j];
			e[j+1]+=e[j];	
		}
	}
	t-=mins;
	if (t<0||q<n){
		puts("0");
		return 0;
	}
	ff[0][0]=1;
	for (int i=0;i<kk;i++)for (int j=0;j<=t;j++){
		if (j+b[i]<=t){
			ff[i][j+b[i]]=(ff[i][j+b[i]]+ff[i][j]);
			if (ff[i][j+b[i]]>=M)ff[i][j+b[i]]-=M;
		}
		ff[i+1][j]=(ff[i+1][j]+ff[i][j]);
		if (ff[i+1][j]>=M)ff[i+1][j]-=M;
	}
	cout << ff[kk][t] << endl;
	return 0;
}