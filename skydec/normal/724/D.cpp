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
const int N=110000;
char a[N];
vector<int>hav[30];
int n,m;
int f[N<<2];
int main(){
	scanf("%d",&m);
	scanf("%s",a+1);
	n=strlen(a+1);
	rep(i,1,n)hav[a[i]-'a'].pb(i);
	rep(i,1,n-m+1)f[i]=0;
	rep(i,n-m+2,n)f[i]=1;
	int all=n-m+1;
	rep(i,0,25){
		int cnt=hav[i].size();
		int use=0;
		int st=0;
		int qian=0;
		int now=1;
		int clr=1;
		rep(j,0,hav[i].size()-1){
			int x=hav[i][j];
			while(now<=x){
				if(!f[now]){
					if(!qian)qian=now;
				}
				++now;
			}
			if(qian==0){
				continue;
			}
			if((j+1==cnt)||(qian+m-1<hav[i][j+1])){
				while(clr<=x){
					//printf("%d %d %d %d\n",clr,x,x-m+1,x+m-1);
					if(clr>=x-m+1)
					if(!f[clr]){
						f[clr]=1;
						all--;
					}
					clr++;
				}
				use++;
				putchar('a'+i);
				qian=0;
			}
		}
		if(all!=0){
			rep(j,1,cnt-use)putchar('a'+i);
		}
	}
	return 0;
}