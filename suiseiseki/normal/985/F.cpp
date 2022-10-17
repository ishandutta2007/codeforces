#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 200000
#define Maxn_w 26
#define arg_1 10007ll
#define arg_2 10009ll
#define mod_1 1000000007ll
#define mod_2 1000000009ll
#define ll long long
char s[Maxn+5];
int cm_1[Maxn+5],cm_2[Maxn+5];
int hash_1[Maxn_w+5][Maxn+5];
int hash_2[Maxn_w+5][Maxn+5];
inline int get_1(int x,int left,int right){
	int ans;
	ans=hash_1[x][right];
	left--;
	if(left>0){
		ans=(int)((ans-(ll)hash_1[x][left]*cm_1[right-left]%mod_1+mod_1)%mod_1);
	}
	return ans;
}
inline int get_2(int x,int left,int right){
	int ans;
	ans=hash_2[x][right];
	left--;
	if(left>0){
		ans=(int)((ans-(ll)hash_2[x][left]*cm_2[right-left]%mod_2+mod_2)%mod_2);
	}
	return ans;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	cm_1[0]=cm_2[0]=1;
	for(register int i=1;i<Maxn;i++){
		cm_1[i]=(int)((ll)cm_1[i-1]*arg_1%mod_1);
		cm_2[i]=(int)((ll)cm_2[i-1]*arg_2%mod_2);
	}
	for(register int i=1;i<=n;i++){
		for(register int j=0;j<Maxn_w;j++){
			hash_1[j][i]=(int)(((ll)hash_1[j][i-1]*arg_1+(1+(('a'+j)==s[i])))%mod_1);
			hash_2[j][i]=(int)(((ll)hash_2[j][i-1]*arg_2+(1+(('a'+j)==s[i])))%mod_2);
		}
	}
	int s,t,len;
	while(m--){
		scanf("%d%d%d",&s,&t,&len);
		multiset<pair<int,int> > st_1,st_2;
		for(register int i=0;i<Maxn_w;i++){
//			printf("%d %d %d %lld %lld %lld %lld\n",i,s,t,get_1(i,s,s+len-1),get_2(i,s,s+len-1),get_1(i,t,t+len-1),get_2(i,t,t+len-1));
			st_1.insert(make_pair(get_1(i,s,s+len-1),get_2(i,s,s+len-1)));
			st_2.insert(make_pair(get_1(i,t,t+len-1),get_2(i,t,t+len-1)));
		}
		if(st_1==st_2){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}