#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int n,p[MN],t[MN],T,mx[MN],mn[MN];
int id[MN],sum[MN];
bool cmp(int a,int b){return p[a]*t[b]>p[b]*t[a];}
bool cmpp(int a,int b){return p[a]<p[b];}
bool chk(double mid){
	double mx=0,tmp=0;
	for(int i=1;i<=n;++i){
		if(i==1||p[id[i]]!=p[id[i-1]])mx=tmp;
		if((double)(1.0-mid*::mx[id[i]]/T)*p[id[i]]<mx){
//			cerr<<"GG: "<<i<<" "<<mid<<": "<<(double)(1.0-mid*::mx[id[i]]/T)*p[id[i]]<<" "<<mx<<endl;
			return 0;
		}
		tmp=max(tmp,(1.0-mid*mn[id[i]]/T)*p[id[i]]);
	}
	return 1;
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i)p[i]=read();
	for(int i=1;i<=n;++i){
		t[i]=read();
		T+=t[i];
	}
	for(int i=1;i<=n;++i)id[i]=i;
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+t[id[i]];
	}
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&p[id[i]]*t[id[j+1]]==p[id[j+1]]*t[id[i]])j++;
		for(int k=i;k<=j;++k){
			mx[id[k]]=sum[j];
			mn[id[k]]=sum[i-1]+t[id[k]];
//			cerr<<id[k]<<": "<<mn[id[k]]<<" "<<mx[id[k]]<<endl;
		}
	}
	double l=0,r=1;
	sort(id+1,id+1+n,cmpp);
	for(int i=1;i<=50;++i){
		double mid=(l+r)/2;
		if(chk(mid))l=mid;
		else r=mid;
	}
	printf("%.10lf",l);
	return 0;
}