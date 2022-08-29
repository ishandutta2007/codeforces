#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
char p[1010000],s[205];int n,m,k;
bool ans[2005];bool hs;bool tmp[2005];
inline bool ck(){
	rep(i,1,k){
		if(tmp[i]<ans[i])return 1;
		if(tmp[i]>ans[i])return 0;
	}
	return 1;
}
int main(){
	gets(p+1);n=strlen(p+1);
	gets(s+1);m=strlen(s+1);
	scanf("%d",&k);
	int part=n/k;
	rep(i,0,m)if(i*part<=m&&m<=i*(part+1)){
		memset(tmp,0,sizeof tmp);int to=i;
		for(int j=k;j>=1;j--){
			bool ck=1;if(!to)break;
			rep(u,0,part){
				if(u*k+j>n&&u*i+to>m)continue;
				if(p[u*k+j]!=s[u*i+to]){ck=0;break;}
			}
			if(!ck)continue;
			tmp[j]=1;to--;
		}
		if(!to){
			if(!hs||ck()){
				hs=1;rep(j,1,k)ans[j]=tmp[j];
			}
		}
	}
	if(!hs)printf("0");
	else rep(i,1,k)printf("%d",ans[i]);
	return 0;
}