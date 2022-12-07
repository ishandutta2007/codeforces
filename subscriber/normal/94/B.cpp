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

int n,x,y,ms[55][55];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> x >> y;
		ms[x-1][y-1]=ms[y-1][x-1]=1;
	}
	for (int i=0;i<5;i++)for (int j=0;j<i;j++)for (int k=0;k<j;k++)if (ms[i][j]&&ms[i][k]&&ms[j][k]||ms[i][j]==0&&ms[i][k]==0&&ms[j][k]==0){
		puts("WIN");
		return 0;
	}
	puts("FAIL");
	return 0;
}