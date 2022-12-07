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

int n,a[111111],x;
long long c[111111],s;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++){
		x=i;
		for (int l=20;l>=0;l--)if (x+pw(l)<n){
			c[x]+=a[i];
			x+=pw(l);
		}
	}
	for (int i=0;i<n-1;i++){
		s+=c[i];
		CC(s);		
	}
	return 0;
}