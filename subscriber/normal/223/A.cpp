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

char a[1111111],e[1111111];
int n,k,ans,l,s[111111],b,h[111111],r;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	n=strlen(a);
	for (int i=0;i<n;i++)s[i+1]=s[i]+(a[i]=='[');
	b=0;
	for (int i=0;i<n;i++)if (a[i]=='('||a[i]=='[')e[k++]=a[i],h[k-1]=i;else{
		if (k==0||abs(a[i]-e[k-1])>3){
			k=0;
			b=i+1;
		}else k--;
		int e=b;
		if (k)e=h[k-1]+1;
		if (s[i+1]-s[e]>ans)ans=s[i+1]-s[e],l=e,r=i;
	}
	CC(ans);
	if (ans)for (int i=l;i<=r;i++)putchar(a[i]);
	puts("");
	return 0;
}