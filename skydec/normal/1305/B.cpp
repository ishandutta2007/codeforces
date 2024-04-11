#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
char s[1005];
int n;
int sf[1005];
bool tag[1005];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	per(i,n,1)sf[i]=sf[i+1]+(s[i]==')');
	
	int now=0;
	int lst=0;
	rep(i,1,n)if(s[i]=='('){
		if(sf[i+1]<=now)break;
		now++;
		tag[i]=1;
		lst=i;
	}
	if(now==0){
		printf("0\n");
		return 0;
	}
	printf("1\n");
	printf("%d\n",2*now);
	rep(i,1,n)if(tag[i])printf("%d ",i);
	vector<int >res;
	per(i,n,lst+1)if(s[i]==')')if(now){now--;res.pb(i);}
	sort(res.begin(),res.end());
	for(int x:res)printf("%d ",x);
	return 0;
}