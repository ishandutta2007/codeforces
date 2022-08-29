#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=25;
pair<int,int>a[N],b[N];
int n,m;
int check0(){
	int ret=0;
	rep(i,n)rep(j,m){
		if(a[i].first==b[j].first&&a[i].second==b[j].second)continue;
		int cur=0;
		if(a[i].first==b[j].first)cur=a[i].first;
		if(a[i].first==b[j].second)cur=a[i].first;
		if(a[i].second==b[j].first)cur=a[i].second;
		if(a[i].second==b[j].second)cur=a[i].second;
		if(cur==0)continue;
		if(ret==0)ret=cur;
		else if(ret!=cur)ret=-1;
	}
	return ret==-1?0:ret;
}
bool check1(){
	rep(i,n)rep(j,m){
		if(a[i].first==b[j].first&&a[i].second==b[j].second)continue;
		int cur=0;
		if(a[i].first==b[j].first)cur=a[i].first;
		if(a[i].first==b[j].second)cur=a[i].first;
		if(a[i].second==b[j].first)cur=a[i].second;
		if(a[i].second==b[j].second)cur=a[i].second;
		if(cur==0)continue;
		int ret=0;
		rep(k,m){
			if(a[i].first==b[k].first&&a[i].second==b[k].second)continue;
			cur=0;
			if(a[i].first==b[k].first)cur=a[i].first;
			if(a[i].first==b[k].second)cur=a[i].first;
			if(a[i].second==b[k].first)cur=a[i].second;
			if(a[i].second==b[k].second)cur=a[i].second;
			if(cur==0)continue;
			if(ret==0)ret=cur;
			else if(ret!=cur)ret=-1;
		}
		if(ret==-1)return 0;ret=0;
		ret=0;
		rep(k,n){
			if(a[k].first==b[j].first&&a[k].second==b[j].second)continue;
			cur=0;
			if(a[k].first==b[j].first)cur=a[k].first;
			if(a[k].first==b[j].second)cur=a[k].first;
			if(a[k].second==b[j].first)cur=a[k].second;
			if(a[k].second==b[j].second)cur=a[k].second;
			if(cur==0)continue;
			if(ret==0)ret=cur;
			else if(ret!=cur)ret=-1;
		}
		if(ret==-1)return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n){
		scanf("%d%d",&a[i].first,&a[i].second);
		if(a[i].first>a[i].second)swap(a[i].first,a[i].second);
	}
	rep(i,m){
		scanf("%d%d",&b[i].first,&b[i].second);
		if(b[i].first>b[i].second)swap(b[i].first,b[i].second);
	}
	int ans;
	ans=check0();
	if(ans){printf("%d\n",ans);
	return 0;}
	printf("%d\n",check1()?0:-1);
	//system("pause");
}