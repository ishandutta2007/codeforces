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

int n,k,x;
char a[111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d\n",&n,&k);	
	gets(a);
	if (n==1){
		puts(a);
		return 0;
	}
	x=0;
	while(k--){
		while (x<n-1&&(a[x]!='4'||a[x+1]!='7'))x++;
		if (x==n-1)break;
		if (x%2){
			if (x&&a[x-1]=='4'&&k>100000)k=k%2+10;
			a[x]='7';
			x--;
		}else{
			if (x<n-2&&a[x+2]=='7'&&k>100000)k=k%2+10;
			a[x+1]='4';
		}
	}
	puts(a);
	return 0;
}