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

int n,k,f[1111111],q[1111111];
long long ans;
char a[1111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d\n",&k);
	gets(a);
	n=strlen(a);
	for (int i=0;i<n;i++)f[i+1]=f[i]+(a[i]=='1');
	q[0]++;
	for (int i=0;i<n;i++){
		int s=f[i+1]-k;
		if (s>=0)ans+=q[s];
		q[f[i+1]]++;		
	}
	CC(ans);
	return 0;
}