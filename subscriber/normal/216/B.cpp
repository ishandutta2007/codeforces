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

int n,m,x,y,ms[111][111],ans,aa,bb,f[111],s1,s2;

void rec(int x){
	if (f[x])return;
	f[x]=1;
	aa++;
	for (int i=0;i<n;i++)if (ms[x][i]){
		bb++;
		rec(i);
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<m;i++){
		cin >> x >> y;
		x--;
		y--;
		ms[x][y]=ms[y][x]=1;
	}
	for (int i=0;i<n;i++)if (!f[i]){
		aa=bb=0;
		rec(i);
		bb/=2;
		if (aa==bb){
			s1+=aa/2;
			s2+=aa/2;
		}else{
			s1+=aa/2;
			s2+=aa/2;
			if (aa%2){
				if (s1<s2)s1++;else s2++;
			}
		}
	}
	if (s2>s1)s2--;
	CC(n-s1-s2);
	return 0;
}