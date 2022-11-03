#include <bits/stdc++.h>
using namespace std;

int n;
int cntl;

struct segtree{
	int cnt[1600005];
	long long sum[1600005][5];

	void upd(int now){
		cnt[now]=cnt[now<<1]+cnt[now<<1|1];
		for(int i=0;i<5;i++){
			sum[now][i]=0;
		}
		for(int i=0;i<5;i++){
			sum[now][i]+=sum[now<<1][i];
		}
		for(int i=0;i<5;i++){
			sum[now][(i+cnt[now<<1])%5]+=sum[now<<1|1][i];
		}
	}
	void add(int to,long long x,int now=1,int nl=0,int nr=cntl-1){
		if(nl==to&&nr==to){
			sum[now][cnt[now]%5]+=x;
			cnt[now]++;
			return;
		}
		int m=(nl+nr)>>1;
		if(m>=to){
			add(to,x,now<<1,nl,m);
		}else{
			add(to,x,now<<1|1,m+1,nr);
		}
		upd(now);
	}
	void del(int to,long long x,int now=1,int nl=0,int nr=cntl-1){
		if(nl==to&&nr==to){
			cnt[now]--;
			sum[now][cnt[now]%5]-=x;
			return;
		}
		int m=(nl+nr)>>1;
		if(m>=to){
			del(to,x,now<<1,nl,m);
		}else{
			del(to,x,now<<1|1,m+1,nr);
		}
		upd(now);
	}
}seg;

map<int,int> lss;
char md[100005][10];
int num[100005];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",md[i]);
		if(md[i][0]!='s'){
			scanf("%d",num+i);
			lss[num[i]];
		}
	}
	for(map<int,int>::iterator it=lss.begin();it!=lss.end();it++){
		it->second=cntl++;
	}
	for(int i=0;i<n;i++){
		if(md[i][0]=='a'){
			seg.add(lss[num[i]],num[i]);
		}else if(md[i][0]=='d'){
			seg.del(lss[num[i]],num[i]);
		}else{
			printf("%I64d\n",seg.sum[1][2]);
		}
	}
	return 0;
}