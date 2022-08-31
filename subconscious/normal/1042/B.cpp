#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=105;
int a[1<<3],n,c,p;
char s[10];
int main(){
	scanf("%d",&n);
	memset(a,0x3f,sizeof a);
	int mx=a[0];a[0]=0;
	rep(i,n){
		scanf("%d%s",&p,s);
		int m=strlen(s);
		c=0;
		for(int j=0;j<m;++j)
			c|=1<<(s[j]-'A');
		for(int j=0;j<8;++j)
			a[j|c]=min(a[j|c],a[j]+p);
	}
	if(a[7]==mx)puts("-1");else printf("%d\n",a[7]);
	return 0;
}