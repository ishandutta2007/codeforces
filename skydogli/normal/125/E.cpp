#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 200005
struct data{
	int a,b,c,id;
	bool friend operator<(data a,data b){
		return a.c<b.c;
	}
}w[2][MN];
int anss,tmp[MN];
int n,m,F,V,Fa[MN],cnt[2];
vector<int>road,ans_road;
data Get(int l,int r){
	if(l>cnt[0])return w[1][r];
	if(r>cnt[1])return w[0][l];
	if(w[0][l]<w[1][r]) return w[0][l];
	return w[1][r];
}
int Find(int a){
	if(Fa[a]==a)return a;
	return Fa[a]=Find(Fa[a]);
}
signed main(){
	n=read();m=read();
	int ned=read();
	int a,b,c;
	int CNTT=0;
	for(int i=1;i<=m;++i){
		a=read();b=read();c=read();int x=0;
		if(a==1||b==1)x=1,CNTT++;
		w[x][++cnt[x]].a=a;w[x][cnt[x]].b=b;w[x][cnt[x]].c=c;
		w[x][cnt[x]].id=i;
	}
	if(CNTT<ned){puts("-1");return 0;}
	sort(w[0]+1,w[0]+1+cnt[0]);
	sort(w[1]+1,w[1]+1+cnt[1]);
	int l=-100005,r=100005;
	int sum;
	while(l+1<r){
		int mid=(l+r)>>1;
		sum=0;
		road.clear();
		for(int i=1;i<=cnt[1];++i)
			tmp[i]=w[1][i].c,w[1][i].c+=mid;
		for(int i=1;i<=n;++i)Fa[i]=i;
		int Cnt=0,CNT1=0,L=1,R=1;
		while(Cnt<n&&(L<=cnt[0]||R<=cnt[1])){
			data x=Get(L,R);
			int fa=Find(x.a),fb=Find(x.b);
			if((x.a==1||x.b==1)&&CNT1>=ned){R++;continue;}
			if(fa!=fb)Fa[fa]=fb,Cnt++,sum+=x.c;
			if(x.c==w[1][R].c&&(x.c!=w[0][L].c||CNT1<ned)) {
				if(fa!=fb)road.push_back(w[1][R].id);
				R++;
				if(fa!=fb)CNT1++;
			}
			else {
				if(fa!=fb)road.push_back(w[0][L].id);
				L++;
			}
		}
		if(Cnt<n-1){puts("-1");return 0;}
		if(CNT1>=ned) {
			l=mid;
			ans_road.clear();
			for(int i=0;i<road.size();++i)
				ans_road.push_back(road[i]);
			anss=sum-ned*l;
		}
		else r=mid;
		for(int i=1;i<=cnt[1];++i)w[1][i].c=tmp[i];
	}
	printf("%d\n",(int)ans_road.size());
	for(int i=0;i<ans_road.size();++i)printf("%d ",ans_road[i]);
	return 0;
}