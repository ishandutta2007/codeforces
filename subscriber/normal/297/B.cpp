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

int n,k,m,x;
map<int,int>a;
map<int,int>::iterator it;
long long s;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> k;	
	for (int i=0;i<n;i++){
		scanf("%d",&x);
		a[k-x]++;
	}
	for (int i=0;i<m;i++){	
		scanf("%d",&x);
		a[k-x]--;
	}
	for (it=a.begin();it!=a.end();it++){
		s+=(*it).S;
		if (s>0){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}