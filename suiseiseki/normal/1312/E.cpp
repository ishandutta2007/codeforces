#include <stack>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
/*int min(int a,int b){
	return a<b?a:b;
}*/
const int Inf=0x3f3f3f3f;
const int Maxn=500;
const int Maxk=1500;
int n;
int f_min[Maxn+5][Maxn+5];
int a[Maxn+5];
stack<int> q;
void init_f(){
	for(int i=1;i<=n;i++){
		while(!q.empty()){
			q.pop();
		}
		for(int j=i;j<=n;j++){
			int now=a[j];
			while(!q.empty()&&now==q.top()){
				now++;
				q.pop();
			}
			q.push(now);
			if(q.size()==1){
				f_min[i][j]=now;
			}
			else{
				f_min[i][j]=-1;
			}
		}
	}
}
/*int f[Maxn+5][Maxn+5][4];
int dfs(int left,int right,int k){
	if(left>=right){
		if(left>right){
			if(k==0){
				return f[left][right][k]=0;
			}
			if(k==1||k==2){
				return f[left][right][k]=1;
			}
			return f[left][right][k]=2;
		}
		if(k==3){
			return f[left][right][k]=2;
		}
		return f[left][right][k]=1;
	}
	if(f[left][right][k]!=-1){
		return f[left][right][k];
	}
	int tmp=f_min[left][right];
	if(tmp==Inf&&k==0){
		return f[left][right][k]=right-left+1;
	}
	f[left][right][k]=right-left+1;
	if(k==1||k==2){
		f[left][right][k]++;
	}
	else if(k==3){
		f[left][right][k]+=2;
	}
//	if(tmp==Inf){
		if(k==1){
			if(a[left]+1==a[left+1]){
				f[left][right][k]=min(dfs(left+1,right,1),f[left][right][k]);
			}
			else{
				f[left][right][k]=min(dfs(left+1,right,0)+1,f[left][right][k]);
			}
		}
		else if(k==2){
			if(a[right]+1==a[right-1]){
				f[left][right][k]=min(dfs(left,right-1,2),f[left][right][k]);
			}
			else{
				f[left][right][k]=min(dfs(left,right-1,0),f[left][right][k]);
			}
		}
		else{
			if(a[left]+1==a[left+1]){
				f[left][right][k]=min(dfs(left+1,right,3),f[left][right][k]);
			}
			else{
				f[left][right][k]=min(dfs(left+1,right,2)+1,f[left][right][k]);
			}
			if(a[right]+1==a[right-1]){
				f[left][right][k]=min(dfs(left,right-1,3),f[left][right][k]);
			}
			else{
				f[left][right][k]=min(dfs(left,right-1,1)+1,f[left][right][k]);
			}
		}
//	}
	if(tmp==Inf){
		return f[left][right][k];
	}
	if(right-left+1==2){
		if(a[left]==a[left+1]){
			if(k==0){
				return f[left][right][k]=1;
			}
			else if(k==1||k==2){
				return f[left][right][k]=2;
			}
			else{
				return f[left][right][k]=1;
			}
		}
		if(k==0){
			return f[left][right][k]=2;
		}
		if(k==1){
			if(a[left]+1==a[right]){
				return f[left][right][k]=1;
			}
			else{
				return f[left][right][k]=2;
			}
		}
		if(k==2){
			if(a[right]+1==a[left]){
				return f[left][right][k]=1;
			}
			else{
				return f[left][right][k]=2;
			}
		}
		return f[left][right][k]=2;
	}
	if(a[left]==a[left+1]){
		if((k&1)==1){
			if(a[left+1]+1==a[left+2]){
				f[left][right][k]=min(dfs(left+2,right,((k&2)|1))+1,f[left][right][k]);
			}
			else{
				f[left][right][k]=min(dfs(left+2,right,(k&2))+2,f[left][right][k]);
			}
		}
		else{
			if(a[left+1]+1==a[left+2]){
				f[left][right][k]=min(dfs(left+2,right,((k&2)|1)),f[left][right][k]);
			}
			else{
				f[left][right][k]=min(dfs(left+2,right,(k&2))+1,f[left][right][k]);
			}
		}
	}
	if(a[right]==a[right-1]){
		if(((k&2)>>1)==1){
			if(a[right-1]+1==a[right-2]){
				f[left][right][k]=min(dfs(left,right-2,(k&1)|2)+1,f[left][right][k]);
			}
			else{
				f[left][right][k]=min(dfs(left,right-2,(k&1))+2,f[left][right][k]);
			}
		}
		else{
			if(a[right-1]+1==a[right-2]){
				f[left][right][k]=min(dfs(left,right-2,(k&1)|2),f[left][right][k]);
			}
			else{
				f[left][right][k]=min(dfs(left,right-2,(k&1))+1,f[left][right][k]);
			}
		}
	}
	for(int i=left;i<right;i++){
		f[left][right][k]=min(dfs(left,i,(k&1))+dfs(i+1,right,(k&2)),f[left][right][k]);
	}
	for(int i=left+1;i<right-1;i++){
		if(a[i]==tmp&&a[i]==a[i+1]){
			f[left][right][k]=min(dfs(left,i-1,(k&1))+dfs(i+2,right,(k&2))+1,f[left][right][k]);
			if(a[i]+1==a[i-1]){
				f[left][right][k]=min(dfs(left,i-1,(k&1)|2)+dfs(i+2,right,(k&2)),f[left][right][k]);
			}
			if(a[i+1]+1==a[i+2]){
				f[left][right][k]=min(dfs(left,i-1,(k&1))+dfs(i+2,right,(k&2)|1),f[left][right][k]);
			}
		}
	}
	return f[left][right][k];
}*/
int f[Maxn+5][Maxk+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	init_f();
//	memset(f,-1,sizeof f);
//	printf("%d\n",dfs(1,n,0));
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for(int j=1;j<=Maxk;j++){
		f[0][j]=1;
	}
	for(int i=1;i<=n;i++){
		f[i][0]=f[i-1][a[i]];
		for(int k=i;k>0;k--){
			if(f_min[k][i]==-1){
				continue;
			}
			f[i][0]=min(f[i][0],f[k-1][0]+1);
			f[i][0]=min(f[i][0],f[k-1][f_min[k][i]]);
		}
		for(int j=1;j<=Maxk;j++){
			f[i][j]=f[i][0]+1;
			for(int k=i;k>0;k--){
				if(f_min[k][i]==-1){
					continue;
				}
				f[i][j]=min(f[i][j],f[k-1][0]+2);
				f[i][j]=min(f[i][j],f[k-1][f_min[k][i]]+1);
				if(f_min[k][i]==j){
					f[i][j]=min(f[i][j],f[k-1][0]+1);
					f[i][j]=min(f[i][j],f[k-1][f_min[k][i]+1]);
				}
			}
		}
	}
	printf("%d\n",f[n][0]);
	return 0;
}