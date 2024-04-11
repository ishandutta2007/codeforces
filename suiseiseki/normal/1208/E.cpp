/*
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 1000000
#define ll long long
vector<int> a[Maxn+5];
int b[Maxn+5];
ll maxn[Maxn+5];
ll ans[Maxn+5];
bool in[Maxn+5];
int n,w;
bool cmp(int p,int q){
	return a[p].size()<a[q].size();
}
ll mn(ll a,ll b){
	return a<b?a:b;
}
int main(){
	scanf("%d%d",&n,&w);
	int len,x;
	ll sum=0;
	ll sum_low=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&len);
		for(int j=1;j<=len;j++){
			scanf("%d",&x);
			a[i].push_back(x);
		}
		maxn[i]=-(1ll<<35);
		sum+=maxn[i];
		sum_low+=maxn[i];
		b[i]=i;
	}
	sort(b+1,b+1+n,cmp);
	int now=1;
	memset(in,1,sizeof in);
	for(int i=0;i<w;i++){
		for(int j=now;j<=n;j++){
			if(a[b[j]][i]>maxn[b[j]]){
				sum-=maxn[b[j]];
				if(maxn[b[j]]<0&&in[b[j]]){
					sum_low-=maxn[b[j]];
				}
				maxn[b[j]]=a[b[j]][i];
				if(i+1>=w-(int)a[b[j]].size()){
					in[b[j]]=0;
				}
				if(!in[b[j]]&&i+1>(int)a[b[j]].size()){
					in[b[j]]=1;
				}
				if(in[b[j]]&&maxn[b[j]]<0){
					sum_low+=maxn[b[j]];
				}
				sum+=maxn[b[j]];
			}
		}
		while(now<=n&&(int)a[b[now]].size()==i+1){
			if(maxn[b[now]]<0&&!in[b[now]]){
				sum_low+=maxn[b[now]];
			}
			now++;
		}
		ans[i+1]=sum-sum_low;
	}
	now=1,sum=0,sum_low=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<((int)a[i].size()>>1);j++){
			swap(a[i][j],a[i][(int)a[i].size()-j-1]);
		}
		maxn[i]=-(1ll<<35);
		sum+=maxn[i];
		sum_low+=maxn[i];
	}
	memset(in,1,sizeof in);
	for(int i=0;i<w;i++){
		for(int j=now;j<=n;j++){
			if(a[b[j]][i]>maxn[b[j]]){
				sum-=maxn[b[j]];
				if(maxn[b[j]]<0&&in[b[j]]){
					sum_low-=maxn[b[j]];
				}
				maxn[b[j]]=a[b[j]][i];
				if(i+1>=w-(int)a[b[j]].size()){
					in[b[j]]=0;
				}
				if(!in[b[j]]&&i+1>(int)a[b[j]].size()){
					in[b[j]]=1;
				}
				if(in[b[j]]&&maxn[b[j]]<0){
					sum_low+=maxn[b[j]];
				}
				sum+=maxn[b[j]];
			}
		}
		while(now<=n&&(int)a[b[now]].size()==i+1){
			if(maxn[b[now]]<0&&!in[b[now]]){
				sum_low+=maxn[b[now]];
			}
			now++;
		}
		ans[w-i]=mn(ans[w-i],sum-sum_low);
	}
	for(int i=1;i<=w;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}
*/
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const int mxn=1e6+6;
ll ans[mxn];
int q[mxn],t[mxn],l[mxn],n,w;
int main() {
	cin>>n>>w;
	for(int ii=1; ii<=n; ++ii) {
		cin>>l[ii];
		for(int i=1; i<=l[ii]; ++i)cin>>t[i];
		t[l[ii]+1]=0;
		int ta=0,x1;
		for(int i=1; i<=l[ii]+1; ++i) {
			for(; ta>=1 and t[q[ta-1]]>=t[q[ta]] and t[i]>=t[q[ta]] and q[ta-1]+w-l[ii]>=i-1; --ta);
			q[++ta]=i;
		}
		x1=q[1];
		if(t[q[1]]<0)x1=w-l[ii]+1;
		for(int i=1; i<=ta; ++i) {
			ans[x1]+=t[q[i]];
			if(i<ta) {
				if(t[q[i]]<t[q[i+1]])x1=q[i+1];
				else x1=q[i]+w-l[ii]+1;
				ans[x1]-=t[q[i]];
			}
		}
	}
	for(int i=1; i<=w; ++i)cout<<(ans[i]+=ans[i-1])<<' ';
	puts("");
	return 0;
}