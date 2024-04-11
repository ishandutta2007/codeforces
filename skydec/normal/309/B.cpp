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
vector<vector<char> >ans;
vector<vector<char> >now;
vector<char>tmp;int R,c;int N;
int len[1010000];
int f[21][1010000];
inline int go(int l){
	int p=R;l--;
	for(int i=20;i>=0;i--)
	if(p&(1<<i)){
		l=f[i][l+1];
		p-=(1<<i);
		if(!l)return N;
	}
	return l;
}
inline void workit(){
	int n=now.size();N=n;
	if(!n)return;
	rep(i,1,n)len[i]=now[i-1].size();
	rep(i,1,n)len[i]+=len[i-1];
	rep(i,1,n){
		int l=i;int r=n;int re=0;
		while(l<r){
			int mid=(l+r)>>1;
			if(len[mid]-len[i-1]+mid-i<=c){
				re=mid;l=mid+1;
			}
			else r=mid;
		}
		if(len[l]-len[i-1]+l-i<=c)re=l;
		f[0][i]=re;
	}
	rep(j,1,20)rep(i,1,n){
		if(!f[j-1][i])f[j][i]=0;
		else f[j][i]=f[j-1][f[j-1][i]+1];
	}
	int al,ar;al=ar=0;ar=-1;
	rep(i,1,n){
		int r=go(i);
		if(r-i+1>=ar-al+1){
			al=i;ar=r;
		}
	}
	if(ar-al+1>ans.size()){
		while(ans.size())ans.pop_back();
		rep(i,al,ar)ans.pb(now[i-1]);
	}
	rep(i,1,n)rep(j,0,20)f[j][i]=0;
}
int n;
int main(){
	scanf("%d%d%d",&n,&R,&c);
	for(int i=1;i<=n;i++){
		while(tmp.size())tmp.pop_back();
		char p=getchar();
		while(!(p<='z'&&p>='a'))p=getchar();
		while(p<='z'&&p>='a')tmp.pb(p),p=getchar();
		if(tmp.size()>c){
			workit();
			while(now.size())now.pop_back();
		}
		else now.pb(tmp);
	}
	workit();
	for(int i=0;i<ans.size();i++){
		int j=i;int tot=ans[i].size();
		while(j+1<ans.size()&&tot+ans[j+1].size()+1<=c){tot+=ans[j+1].size()+1;j++;}
		rep(k,i,j){
			rep(p,0,ans[k].size()-1)printf("%c",ans[k][p]);
			if(k!=j)printf(" ");else printf("\n");
		}
		i=j;
	}
}