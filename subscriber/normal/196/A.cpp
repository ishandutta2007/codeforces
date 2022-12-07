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

char a[1111111];
int n,p[111111][33],x;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	int n=strlen(a);
	for (int i=0;i<26;i++)p[n][i]=-1;
	for (int i=n-1;i>=0;i--){
		for (int j=0;j<26;j++)p[i][j]=p[i+1][j];
		p[i][a[i]-'a']=i;
	}
	x=0;
	while (x<n){
		for (int i=25;i>=0;i--)if (p[x][i]!=-1){
			putchar(i+'a');
			x=p[x][i]+1;
			break;
		}
	}
	puts("");
	return 0;
}