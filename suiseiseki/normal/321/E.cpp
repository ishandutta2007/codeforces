#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxk=800;
const int Maxn=4000;
int u[Maxn+5][Maxn+5];
int sum_u[Maxn+5][Maxn+5];
int sum_v[Maxn+5][Maxn+5];
int n,k;
int f[Maxn+5][Maxn+5];
inline int find_sum(int l,int r){
	if(l>r){
		return 0;
	}
	return sum_v[r][r]-sum_v[l-1][r];
}
int st[Maxn+5][Maxn+5];
int front[Maxn+5],tail[Maxn+5];
int lst[Maxn+5],nxt[Maxn+5];
int q[Maxn+5],q_f,q_t;
bool in[Maxn+5];
inline int calc_id(int j,int x,int y){
	int left=max(x,y)+1,right=n;
	while(left<right){
		int mid=(left+right)>>1;
		if(f[x][j]+find_sum(x+1,mid)>=f[y][j]+find_sum(y+1,mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	if(f[x][j]+find_sum(x+1,left)<f[y][j]+find_sum(y+1,left)){
		return n+1;
	}
	return left;
}
int main(){
	read(n),read(k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			read(u[j][i]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sum_u[i][j]=sum_u[i][j-1]+u[i][j];
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			sum_v[i][j]=sum_v[i-1][j]+sum_u[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		f[i][1]=find_sum(1,i);
	}
	for(int j=2;j<=k;j++){
		for(int i=1;i<=n;i++){
			tail[i]=0;
			front[i]=1;
		}
		q_f=1,q_t=0;
		q[++q_t]=j-1;
		lst[q_t]=nxt[q_t]=0;
		in[q_t]=1;
		for(int i=j;i<=n;i++){
			while(front[i]<=tail[i]){
				int id=st[i][front[i]++];
				if(in[id]==0){
					continue;
				}
				if(lst[id]==q_f){
					q_f=id;
				}
				in[lst[id]]=0;
				lst[id]=lst[lst[id]];
				nxt[lst[id]]=id;
				if(id!=q_f){
					int tmp=calc_id(j-1,q[lst[id]],q[id]);
					st[tmp][++tail[tmp]]=id;
				}
			}
			f[i][j]=find_sum(q[q_f]+1,i)+f[q[q_f]][j-1];
			q[++q_t]=i;
			in[q_t]=1;
			nxt[q_t-1]=q_t;
			lst[q_t]=q_t-1;
			nxt[q_t]=0;
			if(q_f<q_t){
				int tmp=calc_id(j-1,q[lst[q_t]],q[q_t]);
				st[tmp][++tail[tmp]]=q_t;
			}
		}
		in[q[q_f]]=0;
		while(q_f!=q_t){
			q_f=nxt[q_f];
			in[q[q_f]]=0;
		}
	}
	printf("%d\n",f[n][k]);
	return 0;
}