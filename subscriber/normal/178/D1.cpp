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

int n,a[55],e[5][5],q,s;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n*n;i++)cin >> a[i],s+=a[i];
	sort(a,a+n*n);
	for (;;){
		int b=0;
		for (int i=0;i<n;i++)for (int j=0;j<n;j++)e[i][j]=a[i*n+j];
		for (int i=0;i<n;i++){
			q=0;
			for (int j=0;j<n;j++)q+=e[i][j];			
			if (q*n!=s)b=1;
		}
		for (int i=0;i<n;i++){
			q=0;
			for (int j=0;j<n;j++)q+=e[j][i];			
			if (q*n!=s)b=1;
		}
		q=0;
		for (int j=0;j<n;j++)q+=e[j][j];			
		if (q*n!=s)b=1;
		q=0;
		for (int j=0;j<n;j++)q+=e[j][n-1-j];			
		if (q*n!=s)b=1;
		if (!b){
			CC(q);
			for (int i=0;i<n;i++){
				for (int j=0;j<n;j++)cout << e[i][j] << " ";
				puts("");
			}
			return 0;
		}
		if (!next_permutation(a,a+n*n))break;
	}
	return 0;
}