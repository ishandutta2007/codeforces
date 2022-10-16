#include <cstdio>
#include <iostream>
#include <algorithm>
const int Maxn=100000;
int n;
int p[Maxn+5];
int a_lst[Maxn+5],a_nxt[Maxn+5],b_lst[Maxn+5],b_nxt[Maxn+5];
std::pair<int,std::pair<int,int> > seg[Maxn<<1|5];
int len;
std::pair<int,std::pair<int,int> > get_val(std::pair<int,std::pair<int,int> > a,std::pair<int,std::pair<int,int> > b){
	if(seg[1]==a||seg[1]==b){
		if(seg[2]==a||seg[2]==b){
			return seg[3];
		}
		return seg[2];
	}
	return seg[1];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	if(n==2){
		puts("0");
		return 0;
	}
	a_lst[1]=b_lst[1]=1;
	for(int i=2;i<=n;i++){
		if(p[i]<p[i-1]){
			a_lst[i]=i;
			b_lst[i]=b_lst[i-1];
		}
		else{
			a_lst[i]=a_lst[i-1];
			b_lst[i]=i;
		}
	}
	a_nxt[n]=b_nxt[n]=n;
	for(int i=n-1;i>0;i--){
		if(p[i]>p[i+1]){
			a_nxt[i]=i;
			b_nxt[i]=b_nxt[i+1];
		}
		else{
			a_nxt[i]=a_nxt[i+1];
			b_nxt[i]=i;
		}
	}
	for(int i=1;i<=n;i++){
		seg[++len]=std::make_pair(a_nxt[i]-a_lst[i]+1,std::make_pair(a_lst[i],a_nxt[i]));
		seg[++len]=std::make_pair(b_nxt[i]-b_lst[i]+1,std::make_pair(b_lst[i],b_nxt[i]));
	}
	std::sort(seg+1,seg+1+len);
	len=std::unique(seg+1,seg+1+len)-seg-1;
	std::reverse(seg+1,seg+1+len);
	int ans=0;
	for(int i=1;i<=n;i++){
		std::pair<int,std::pair<int,int> > t_1=std::make_pair(a_nxt[i]-a_lst[i]+1,std::make_pair(a_lst[i],a_nxt[i]));
		std::pair<int,std::pair<int,int> > t_2=std::make_pair(b_nxt[i]-b_lst[i]+1,std::make_pair(b_lst[i],b_nxt[i]));
		int dis=std::max(i-a_lst[i]+1,b_nxt[i]-i+1);
		if(i-a_lst[i]==0||b_nxt[i]-i==0){
			continue;
		}
//		printf("%d %d %d %d %d %d %d\n",i,dis,a_lst[i],a_nxt[i],b_lst[i],b_nxt[i],get_val(t_1,t_2).first);
		if(get_val(t_1,t_2).first>=dis){
			continue;
		}
		if(std::max(a_nxt[i]-i,i-b_lst[i])>=dis){
			continue;
		}
		if(std::min(i-a_lst[i],b_nxt[i]-i)<dis-(dis&1)){
			continue;
		}
		if(std::min(i-a_lst[i],b_nxt[i]-i)>1&&(dis&1)){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
7
2 4 5 7 3 6 1
*/