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

int f[222222][2][2],n;
char a[222222],b[222222];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d\n",&n);
	gets(a);
	gets(b);
	f[0][0][0]=1;
	for (int i=0;i<n;i++)for(int aa=0;aa<2;aa++)for (int bb=0;bb<2;bb++)
	for (char A='0';A<='9';A++)for (char B='0';B<='9';B++)if ((a[i]=='?'||a[i]==A)&&(b[i]=='?'||b[i]==B))
	f[i+1][aa||(A>B)][bb||(B>A)]=(f[i+1][aa||(A>B)][bb||(B>A)]+f[i][aa][bb])%M;
	cout << f[n][1][1] << endl;
	return 0;
}