#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<bitset>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=100005;
char s[N];
char t[N];
int n,Q;
bitset<N>f[27];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n)f[s[i]-'a'][i]=1;
	scanf("%d",&Q);
	while(Q--){
		int ty;scanf("%d",&ty);
		if(ty==1){
			int x;char ss[4];scanf("%d",&x);scanf("%s",ss);
			f[s[x]-'a'][x]=0;
			s[x]=ss[0];
			f[s[x]-'a'][x]=1;
		}
		else{
			int l,r;scanf("%d%d",&l,&r);
			scanf("%s",t+1);
			int len=strlen(t+1);
			r-=len-1;
			if(r<l){
				puts("0");
				continue;
			}
			bitset<N> gt;gt.reset();gt=~gt;
			rep(i,1,len)gt&=(f[t[i]-'a']>>(i-1));

			gt>>=l;
			int ans=gt.count();
			gt>>=(r-l+1);
			ans-=gt.count();
			printf("%d\n",ans);
		}
	}
	return 0;
}