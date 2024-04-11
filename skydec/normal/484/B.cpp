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
const int N=210000;
int a[N];int n;
int big[2010000];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);big[a[i]]=a[i];
	}
	rep(i,1,2000000)if(!big[i])big[i]=big[i-1];
	
	int ans=0;
	rep(i,1,1000000)if(big[i]==i){
		for(int j=i*2;j<=2000000;j+=i)if(big[j-1]){
			if(big[j-1]%i>ans&&big[j-1]>=i){
				ans=big[j-1]%i;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}