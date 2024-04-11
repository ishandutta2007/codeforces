#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,m;
char str[1000010];
bool used[1000010];
int ps[1000010];
int tre[1000010];
void upd(int x,int k){
	while(x<=m){
		tre[x]+=k;x+=x&-x;
	}
}
int qry(int x){
	int res=0;
	while(x){
		res+=tre[x];x-=x&-x;
	}
	return res;
}
void update(int l,int r){
	if(l<=r) upd(l+1,1),upd(r+2,-1);
	else{
		upd(l+1,1);upd(1,1);upd(r+2,-1);
	}
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();// 0 ~ m
		for(int i=1;i<=m;++i) tre[i]=0;
		for(int i=0;i<m;++i) used[i]=0;
		scanf("%s",str);
		int cnt=0,lst=-1145141919;
		for(int i=0;i<n*m;++i){
			int t=i%m;
			if(str[i]=='1'){
				if(!used[t]) ++cnt,used[t]=1;
				if(lst<=i-m) update(0,m-1);
				else{
					update(lst%m,(i-1+m)%m);
				}
				lst=i;
			}
			printf("%d ",cnt+qry(i%m+1));
		}
		printf("\n");
	}
}