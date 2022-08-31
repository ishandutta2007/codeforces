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
int one[30][N];
int zero[30][N];
int a[N];
int left[N];
vector<int>Q[30][N];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	rep(i,1,m){
		int l,r,q;scanf("%d%d%d",&l,&r,&q);
		rep(j,0,29){
			if(q&(1<<j))one[j][l]++,one[j][r+1]--;
			else Q[j][r].pb(l);
		}
	}
	rep(j,0,29){
		memset(left,0,sizeof left);
		int a1=0;
		rep(i,1,n){
			a1+=one[j][i];
			if(a1){a[i]+=(1<<j);left[i]=left[i-1]+1;}
			else left[i]=0;
			rep(k,0,Q[j][i].size()-1){
				int L=Q[j][i][k];
				if(i-L+1<=left[i]){
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	printf("YES\n");
	rep(i,1,n)printf("%d ",a[i]);
	return 0;
}