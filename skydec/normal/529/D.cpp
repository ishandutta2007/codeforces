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
const int N=20005;
int t[N];int ans[N];
multiset<int>use,nouse;
int c[N];int kind=0;
int main(){
	int n,M,T;
	scanf("%d%d%d",&n,&M,&T);
	rep(i,1,n){
		int h,m,s;
		scanf("%d:%d:%d",&h,&m,&s);
		t[i]=h*3600+m*60+s;
	}
	int R=0;int l=1;bool arrive=0;
	rep(i,1,n){
		while(t[l]+T-1<t[i]){
			use.erase(use.find(ans[l]));c[ans[l]]--;if(c[ans[l]]==0)kind--;
			l++;
		}
		if(kind==M){
                        if(!use.size())return 0;
			arrive=1;
			ans[i]=*(--use.end());
			c[ans[i]]++;use.insert(ans[i]);
		}
		else{
			ans[i]=++R;
			use.insert(ans[i]);
			c[ans[i]]++;
			kind++;
		}
	}
        if(kind==M)arrive=1;
	if(!arrive){
		printf("No solution\n");
	}
	else{
		printf("%d\n",R);
		rep(i,1,n)printf("%d\n",ans[i]);
	}
}