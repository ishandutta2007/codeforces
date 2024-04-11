#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define int long long
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int x,y;
int x1,y1;
int cnt;
vector<pair<PII,int> >ans;
void exgcd(int a,int b){
	if(!b){
		x1=1,y1=0;return ;
	}
	else{
		exgcd(b,a%b);
		int t=y1;
		y1=x1-(a/b)*y1;
		x1=t;
	}
}
signed main(){
	x=read();
	int a=1;
	while(a<=x) a<<=1;
	a>>=1;
	int tmp=x;
	while(a>1){
		++cnt;ans.pb(mp(mp(tmp,tmp),1));tmp<<=1;a>>=1;
	}
	++cnt;ans.pb(mp(mp(tmp,x),2));
	y=tmp^x;
	exgcd(x,y);
	if(x1<0) x1=-x1;
	if(y1<0) y1=-y1;
	tmp=x;
	int res=0;
	while(x1){
		if(x1&1){
			if(!res) res=tmp;
			else {
				++cnt;
				ans.pb(mp(mp(res,tmp),1));res+=tmp;
			}
		}
		x1>>=1;
		if(x1){
			++cnt;
			ans.pb(mp(mp(tmp,tmp),1));
			tmp<<=1;
		}
	}
	int res1=0;
	tmp=y;
	while(y1){
		if(y1&1){
			if(!res1) res1=tmp;
			else {
				++cnt;
				ans.pb(mp(mp(res1,tmp),1));res1+=tmp;
			}
		}
		y1>>=1;
		if(y1){
			++cnt;
			ans.pb(mp(mp(tmp,tmp),1));
			tmp<<=1;
		}
	}
	if(min(res1,res)&1){
		++cnt;
		ans.pb(mp(mp(res,x),1));
		++cnt;
		ans.pb(mp(mp(res1,x),1));
		res+=x,res1+=x;
	}
	++cnt;
	ans.pb(mp(mp(res,res1),2));
	printf("%lld\n",cnt);
	for(auto i:ans){
		if(i.se==1){
			printf("%lld + %lld\n",i.fi.fi,i.fi.se);
		}
		else{
			printf("%lld ^ %lld\n",i.fi.fi,i.fi.se);
		}
	}
}