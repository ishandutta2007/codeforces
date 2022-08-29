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
const int N=110000;
int n;
int res[N*20];
int ji[N*20];
int w[N*20];
int m;
vector<int> uni(vector<int> a){
	vector<int> b;b.clear();
	rep(i,0,a.size()-1)if(i==0||a[i]!=a[i-1])b.push_back(a[i]);
	return b;
}
int calc(vector<int> a){
	int now=++m;
	if((a.size()==1&&a[0]==0)||(a.size()==0)){
		res[now]=0;
		return now;
	}
	if(a.size()==1&&abs(a[0])==1){
		res[now]=1;
		ji[now]=0;
		w[now]=a[0];
		return now;
	}
	if(a.size()==2&&abs(a[0])+abs(a[1])==1){
		res[now]=1;
		ji[now]=0;
		w[now]=a[0]+a[1];
		return now;
	}
	bool fg=0;
	rep(i,0,a.size()-1)if(a[i]%2!=0)fg=1;
	if(!fg){
		vector<int> b=a;
		rep(i,0,b.size()-1)b[i]/=2;
		int t=calc(b);
		res[now]=res[t];
		ji[now]=t;
		w[now]=0;
		return now;
	}
	else{
		res[now]=1000000000;
		for(int x=-1;x<=1;x+=2){
			vector<int> b=a;
			rep(i,0,b.size()-1)if(b[i]%2!=0)b[i]=(b[i]+x)/2;else b[i]/=2;
			vector<int> c=uni(b);
			int t=calc(c);
			if(res[t]+1<res[now]){
				res[now]=res[t]+1;
				w[now]=-x;
				ji[now]=t;
			}
		}
		return now;
	}
}
void cput(int x,int b){
	if(res[x]==0)return;
	if(w[x]!=0)printf("%d ",w[x]*b);
	cput(ji[x],b*2);
}
int main(){
	scanf("%d",&n);
	vector<int> a;a.clear();
	rep(i,1,n){
		int x;scanf("%d",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int id=calc(uni(a));
	printf("%d\n",res[id]);
	cput(id,1);
	puts("");
	return 0;
}