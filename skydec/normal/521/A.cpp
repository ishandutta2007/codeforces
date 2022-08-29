#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=110000;
int n;
const int P=1000000007;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
char a[N];int b[N];
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	rep(i,1,n){
		if(a[i]=='A')b[1]++;
		else if(a[i]=='C')b[2]++;
		else if(a[i]=='T')b[3]++;
		else b[4]++;
	}
	sort(b+1,b+1+4);
	

	if(b[1]==b[4]){
		printf("%d\n",Pow(4,n));
		return 0;
	}
	else if(b[2]==b[4]){
		printf("%d\n",Pow(3,n));
		return 0;
	}
	else if(b[3]==b[4]){
		printf("%d\n",Pow(2,n));
	}
	else printf("%d\n",Pow(1,n));
	return 0;
}