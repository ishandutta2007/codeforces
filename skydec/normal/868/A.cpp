#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=105;
char dd[N][5];
int main(){
	char pa[4];
	scanf("%s",pa+1);
	int n;scanf("%d",&n);
	rep(i,1,n)scanf("%s",dd[i]+1);
	rep(i,1,n)if(dd[i][1]==pa[1]&&dd[i][2]==pa[2]){
		puts("YES");
		return 0;
	}
	rep(i,1,n)rep(j,1,n)if(dd[i][2]==pa[1]&&dd[j][1]==pa[2]){
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}