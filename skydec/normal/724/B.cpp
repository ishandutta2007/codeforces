#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
#include<vector>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)((x).size()))
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double DB;
const DB pi=acos(-1.0);
const int N=25;
int a[N][N],n,m;
int b[N];
bool check(int x,int y){
	rep(i,1,n){
		rep(j,1,m)b[j]=a[i][j];
		bool ok=0;
		rep(j,1,m)rep(k,1,m){
			swap(b[j],b[k]);
			swap(b[x],b[y]);
			bool flag=1;
			rep(l,1,m)if(b[l]!=l){
				flag=0;
				break;
			}
			if(flag){ok=1;break;}
			swap(b[x],b[y]);
			swap(b[j],b[k]);
			
			swap(b[x],b[y]);
			swap(b[j],b[k]);
			flag=1;
			rep(l,1,m)if(b[l]!=l){
				flag=0;
				break;
			}
			if(flag){ok=1;break;}
			swap(b[j],b[k]);
			swap(b[x],b[y]);
		}
		if(!ok)return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]);
	rep(i,1,m)rep(j,1,m)
	if(check(i,j)){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}