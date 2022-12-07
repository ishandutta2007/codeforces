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

int n,ans=0,s[111111];
pair<int,int>q[111111];

int find(int x){
	int r=0;
	while(x){
		r=max(r,s[x]);
		x&=x-1;
	}
	return r;
}

void add(int x,int v){
	while (x<=n){
		s[x]=max(s[x],v);
		x=x+x-(x&(x-1));
	}
}


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> q[i].F >> q[i].S;
	sort(q,q+n);
	for (int i=0;i<n;i++){	
		if (find(i+1)>=q[i].S)ans++;
		add(i+1,q[i].S);
	}
	CC(ans);
	return 0;
}