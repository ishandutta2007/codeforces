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

char a[111111];
int g[11],g1[11],g2[11],ans=-1,l,k1=0,k2=0,a1[111111],a2[111111],n,xx;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	n=strlen(a);
	for (int i=0;i<n;i++)g[a[i]-'0']++;
	for (int x=0;x<=g[0];x++){
	for (int i=1;i<10;i++){
		int t=x;
		for (int j=0;j<10;j++)g1[j]=g2[j]=g[j];
		g1[0]-=x;
		g2[0]-=x;
		if (g1[i]&&g2[10-i]){
			t++;
			g1[i]--;
			g2[10-i]--;
			for (int j=0;j<10;j++)t+=min(g1[j],g2[9-j]);
		}
		if (t>ans)ans=t,l=i,xx=x;
	}
	}
	if (ans<1){
		puts(a);
		puts(a);
		return 0;
	}
	for (int j=0;j<10;j++)g1[j]=g2[j]=g[j];
	for (int i=0;i<xx;i++){
		a1[k1++]=0;
		a2[k2++]=0;
		g1[0]--;
		g2[0]--;
	}
	if (g1[l]&&g2[10-l]){
	a1[k1++]=l;
	a2[k2++]=10-l;
	g1[l]--;
	g2[10-l]--;
	for (int i=0;i<10;i++)while(g1[i]&&g2[9-i]){
		a1[k1++]=i;
		a2[k2++]=9-i;
		g1[i]--;
		g2[9-i]--;	
	}
	}
	for (int i=0;i<10;i++)while (g1[i]){
		a1[k1++]=i;
		g1[i]--;
	}
	for (int i=0;i<10;i++)while (g2[i]){
		a2[k2++]=i;
		g2[i]--;
	}
	for (int i=n-1;i>=0;i--)printf("%d",a1[i]);
	puts("");
	for (int i=n-1;i>=0;i--)printf("%d",a2[i]);
	puts("");
	return 0;
}