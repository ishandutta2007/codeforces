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

int n,x,y,w[111111];


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		int s=sqrt(x)+1e-9;
		int an=0;
		for (int j=1;j<=s;j++)if (x%j==0){
			int e=j;
			if (w[e]<=i-y)an++;
			w[e]=i+1;
			if (j*j!=x){
				int e=x/j;
				if (w[e]<=i-y)an++;
				w[e]=i+1;
			}
		}
		printf("%d\n",an);
	}
	return 0;
}