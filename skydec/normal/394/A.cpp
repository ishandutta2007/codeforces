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
char a[505];int n;
int cnt[4];int top=0;
void Out(){
	rep(i,1,cnt[0])printf("|");
	printf("+");
	rep(i,1,cnt[1])printf("|");
	printf("=");
	rep(i,1,cnt[2])printf("|");
}
int main(){
	scanf("%s",a+1);n=strlen(a+1);
	rep(i,1,n){
		if(a[i]=='='||a[i]=='+')top++;
		if(a[i]=='|')cnt[top]++;
	}
	if(cnt[0]+cnt[1]==2+cnt[2]){
		if(cnt[0]>1)cnt[0]--;else cnt[1]--;
		cnt[2]++;
		Out();
		return 0;
	}
	else if(cnt[0]+cnt[1]+2==cnt[2]){
		cnt[0]++;cnt[2]--;
		Out();
		return 0;
	}
	else if(cnt[0]+cnt[1]==cnt[2]){
		Out();
		return 0;
	}
	printf("Impossible\n");
	return 0;
}