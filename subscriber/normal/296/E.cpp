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

pair<int,int>w[55][55][222][2];
long long C[55][55];
int a,b,k,n,x;

pair<int,int>rec(int aa,int bb,int o,int rr){
	if (rr>200)return mp(1000000000,0);
	if (a==aa&&b==bb)return mp(0,1);
	pair<int,int>r=mp(1000000000,0);
	if (w[aa][bb][rr][o].F)return w[aa][bb][rr][o];
	if (o==0){
		for (int i=0;i<=a-aa;i++)for (int j=0;j<=b-bb;j++)if (i+j>0&&i+j+j<=k){
			pair<int,int>g=rec(aa+i,bb+j,1,rr+1);
			g.S=g.S*C[a-aa][i]%M*C[b-bb][j]%M;
			if (g.F<r.F)r=g;else if (g.F==r.F)r.S=(r.S+g.S)%M;
		}
	}else{
		for (int i=0;i<=aa;i++)for (int j=0;j<=bb;j++)if (i+j>0&&i+j+j<=k){
			pair<int,int>g=rec(aa-i,bb-j,0,rr+1);
			g.S=g.S*C[aa][i]%M*C[bb][j]%M;
			if (g.F<r.F)r=g;else if (g.F==r.F)r.S=(r.S+g.S)%M;
		}
	}
	r.F++;
	return w[aa][bb][rr][o]=r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	for (int i=0;i<=50;i++)for (int j=0;j<=i;j++)if (j==0||i==j)C[i][j]=1;else C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
	cin >> n >> k;
	k/=50;
	for (int i=0;i<n;i++){
		cin >> x;
		if (x==50)a++;else b++;
	}
	pair<int,int>o=rec(0,0,0,0);
	if (o.F>=1e9)o.F=-1;
	cout << o.F << endl << o.S << endl;
	return 0;
}