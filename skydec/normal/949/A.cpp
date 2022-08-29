#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
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
const int N=210000;
char a[N];
int n;
vector<int> ans[N];
set<int>p0,p1;
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	rep(i,1,n)a[i]-='0';
	int w=0;
	rep(i,1,n)if(a[i]==0)++w;else --w;
	int k=w;
	int now=0;
	int d=0;
	rep(i,1,n){
		if(a[i]==0){
			if(d<k){
				p0.insert(++d);
				ans[d].push_back(i);
			}
			else{
				if(p1.size()==0){
					printf("-1\n");
					return 0;
				}
				int x=*p1.begin();
				p1.erase(x);
				p0.insert(x);
				ans[x].push_back(i);
			}
		}
		else{
			if(p0.size()==0){
				printf("-1\n");
				return 0;
			}
			int x=*p0.begin();
			p0.erase(x);
			p1.insert(x);
			ans[x].push_back(i);
		}
	}
	if((p1.size()>0)||(d!=k)){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",d);
	rep(i,1,d){
		printf("%d ",ans[i].size());
		rep(j,0,ans[i].size()-1)printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}