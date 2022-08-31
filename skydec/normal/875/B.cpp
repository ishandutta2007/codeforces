#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=310000;
int n,p[N];
int hav[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&p[i]);
	printf("1 ");
	int bd=n;
	rep(i,1,n){
		hav[p[i]]=1;
		while(hav[bd])--bd;
		printf("%d ",1+(i-(n-bd)));
	}
	return 0;
}