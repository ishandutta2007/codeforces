#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 200000
int a[3][Maxn+5];
bool vis[3][Maxn+5];
int sum[3][Maxn+5];
int k[3],n;
struct Segment{
	int left,right;
	int val;
}seg[Maxn+5];
int mn(int a,int b){
	return a<b?a:b;
}
struct Segment_Node{
	int left,right;
	int sum,rsum;
}node[Maxn<<2|5];
void build(int root,int left,int right){
	node[root].left=left;
	node[root].right=right;
	if(left==right){
		if(vis[0][left]){
			node[root].sum=node[root].rsum=1;
		}
		else if(vis[1][left]){
			node[root].sum=node[root].rsum=-1;
		}
		else{
			node[root].sum=node[root].rsum=0;
		}
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	node[root].sum=node[root<<1].sum+node[root<<1|1].sum;
	node[root].rsum=mn(node[root<<1|1].rsum,node[root<<1|1].sum+node[root<<1].rsum);
}
pair<int,int> query(int root,int left,int right){
	if(node[root].left==left&&node[root].right==right){
		return make_pair(node[root].sum,node[root].rsum);
	}
	root<<=1;
	if(right<=node[root].right){
		return query(root,left,right);
	}
	root|=1;
	if(left>=node[root].left){
		return query(root,left,right);
	}
	root>>=1;
	pair<int,int> l=query(root<<1,left,node[root<<1].right),r=query(root<<1|1,node[root<<1|1].left,right);
	return make_pair(l.first+r.first,mn(r.second,l.second+r.first));
}
int main(){
	scanf("%d%d%d",&k[0],&k[1],&k[2]);
	for(int i=0;i<3;i++){
		for(int j=1;j<=k[i];j++){
			scanf("%d",&a[i][j]);
			vis[i][a[i][j]]=1;
		}
		sort(a[i]+1,a[i]+1+k[i]);
	}
	n=k[0]+k[1]+k[2];
	int len=0;
	seg[++len].left=0;
	seg[len].right=0;
	seg[len].val=0;
	for(int i=1,j;i<=n;i=j+1){
		int tmp;
		if(vis[0][i]){
			tmp=0;
		}
		else if(vis[1][i]){
			tmp=1;
		}
		else{
			tmp=2;
		}
		j=i;
		while(j<=n&&vis[tmp][j]){
			j++;
		}
		j--;
		seg[++len].left=i;
		seg[len].right=j;
		seg[len].val=tmp;
	}
	build(1,1,n);
	int ans=n+1;
	for(int i=1;i<=n;i++){
		sum[0][i]=sum[0][i-1];
		sum[1][i]=sum[1][i-1];
		sum[2][i]=sum[2][i-1];
		if(vis[0][i]){
			sum[0][i]++;
		}
		else if(vis[1][i]){
			sum[1][i]++;
		}
		else{
			sum[2][i]++;
		}
	}
	int tmp=0;
	for(int i=0;i<=n;i++){
		if(sum[1][i]+sum[0][n]-sum[0][i]+k[2]<ans){
			ans=sum[1][i]+sum[0][n]-sum[0][i]+k[2];
			tmp=i;
		}
	}
	int id=0;
	for(int i=1;i<=len;i++){
		if(seg[i].val==0&&seg[i].right==tmp){
			id=i;
			break;
		}
	}
	int num_1=0,num_2=ans;
	pair<int,int> it;
	for(int i=len;i>1;i--){
		if(seg[i].val!=2){
			num_1+=seg[i].right-seg[i].left+1;
			if(i>id){
				if(seg[i].val==0){
					num_2-=seg[i].right-seg[i].left+1;
				}
			}
			else{
				while(id>1){
					id--;
					while(seg[id].val!=0){
						if(seg[id].val==1){
							num_2-=seg[id].right-seg[id].left+1;
						}
						id--;
					}
					if(id==1){
						break;
					}
					it=query(1,1,seg[id].right);
					if(it.second>=0){
						break;
					}
					num_2+=seg[id].right-seg[id].left+1;
				}
			}
		}
		else{
			num_2-=seg[i].right-seg[i].left+1;
		}
//		printf("%d %d %d %d\n",seg[i].left,seg[i].right,num_1,num_2);
		ans=mn(ans,num_1+num_2);
	}
	printf("%d\n",ans);
	/*int left,right,mid;
	pair<int,int> it;
	for(int i=n+1;i>0;i--){
		left=1,right=i-1;
		while(left<right){
			mid=(left+right)>>1;
//			printf("%d %d %d %d\n",left,right,mid,i-1);
			it=query(1,mid,i-1);
//			puts("Out");
			if(it.second<0){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		left--;
		ans=mn(ans,((n-i+1)-(sum[2][n]-sum[2][i-1]))+(left-sum[0][left])+((i-1)-left-(sum[1][i-1]-sum[1][left])));
	}
	printf("%d\n",ans);*/
	return 0;
}