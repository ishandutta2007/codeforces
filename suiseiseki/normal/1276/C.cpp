//#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Maxn 400000
int a[Maxn+5];
int b[Maxn+5];
struct Node{
	int len,id;
	friend bool operator <(Node p,Node q){
		return p.len>q.len;
	}
}c[Maxn+5];
int d[Maxn+5];
int n,m;
vector<int> ans[Maxn+5];
//multiset<int> st;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+1+m,a[i])-b;
		c[a[i]].len++;
		c[a[i]].id=b[a[i]];
	}
	sort(c+1,c+1+m);
	for(int i=1;i<=m;i++){
//		st.insert(c[i]);
		d[i]=c[i].len;
	}
	int ans_row=1,ans_line=m;
	int row=1,line=m;
//	multiset<int>::iterator it;
	int free=0;
	int left,right,mid;
	int sz;
	for(row=2;row<=n;row++){
		left=1,right=line+1;
		d[right]=0;
		while(left<right){
			mid=(left+right)>>1;
			if(d[mid]<row){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		for(int i=left;i<=line;i++){
			free+=d[i];
		}
		line=left-1;
		sz=free/row;
		if(row>line+sz){
			break;
		}
		if(row*(line+sz)>ans_row*ans_line){
			ans_row=row;
			ans_line=line+sz;
		}
	}
	printf("%d\n",ans_row*ans_line);
	printf("%d %d\n",ans_row,ans_line);
	for(int i=1;i<=ans_row;i++){
		for(int j=0;j<=ans_line;j++){
			ans[i].push_back(0);
		}
	}
	for(int i=1;i<=m;i++){
		d[i]=c[i].len;
	}
	int k=1;
	for(int i=1;i<=ans_line;i++){
		for(int j=1,l=i;j<=ans_row;j++,l=(l==ans_line?1:l+1)){
			ans[j][l]=c[k].id;
			d[k]--;
			if(d[k]==0){
				k++;
			}
		}
		if(c[k].len>ans_row){
			k++;
		}
	}
	for(int i=1;i<=ans_row;i++){
		for(int j=1;j<=ans_line;j++){
			printf("%d ",ans[i][j]);
		}
		puts("");
	}
	return 0;
}