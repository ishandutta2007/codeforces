#include <vector>
#include <cstdio>
const int Maxn=100000;
int n;
int a[Maxn+5];
struct Operation{
	int x,y,z;
	Operation(int _x=0,int _y=0,int _z=0){
		x=_x,y=_y,z=_z;
	}
};
bool vis[1<<12|5];
std::vector<Operation> op[1<<12|5];
int qu[1<<12|5],qu_f,qu_t;
std::vector<Operation> ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int _n=n;
	n=std::min(n,12);
	qu_f=1,qu_t=0;
	vis[0]=1;
	qu_f=1,qu_t=0;
	qu[++qu_t]=0;
	while(qu_f<=qu_t){
		int mask=qu[qu_f++];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int k=j+(j-i);
				if(k>=n){
					continue;
				}
				int nmask=mask^(1<<i)^(1<<j)^(1<<k);
				if(!vis[nmask]){
					vis[nmask]=1;
					op[nmask]=op[mask];
					op[nmask].push_back(Operation(i,j,k));
					qu[++qu_t]=nmask;
				}
			}
		}
	}
	n=_n;
	if(n<12){
		int mask=0;
		for(int i=1;i<=n;i++){
			mask|=a[i]<<(i-1);
		}
		if(!vis[mask]){
			puts("NO");
			return 0;
		}
		puts("YES");
		printf("%d\n",(int)op[mask].size());
		for(Operation i:op[mask]){
			printf("%d %d %d\n",i.x+1,i.y+1,i.z+1);
		}
		return 0;
	}
	for(int i=1;i<=n-12;i++){
		while(i<=n-12&&a[i]==0){
			i++;
		}
		if(i>n-12){
			break;
		}
		if(a[i]==1){
			if(a[i+1]==1){
				if(a[i+2]==1){
					ans.push_back(Operation(i,i+1,i+2));
					a[i]^=1,a[i+1]^=1,a[i+2]^=1;
				}
				else{
					int mask=0;
					bool flag=1;
					for(int j=0;j<12;j++){
						mask|=(a[i+j]<<j);
						if((int)op[mask].size()<=j/3){
							for(Operation k:op[mask]){
								ans.push_back(Operation(k.x+i,k.y+i,k.z+i));
								a[k.x+i]^=1,a[k.y+i]^=1,a[k.z+i]^=1;
							}
							flag=0;
							break;
						}
					}
					if(flag){
						ans.push_back(Operation(i,i+1,i+2));
						a[i]^=1,a[i+1]^=1,a[i+2]^=1;
					}
				}
			}
			else if(a[i+2]==1){
				ans.push_back(Operation(i,i+2,i+4));
				a[i]^=1,a[i+2]^=1,a[i+4]^=1;
			}
			else{
				ans.push_back(Operation(i,i+3,i+6));
				a[i]^=1,a[i+3]^=1,a[i+6]^=1;
			}
		}
	}
	int mask=0;
	for(int i=n-11;i<=n;i++){
		mask|=a[i]<<(i-n+11);
	}
	for(Operation i:op[mask]){
		ans.push_back(Operation(i.x+n-11,i.y+n-11,i.z+n-11));
		a[i.x+n-11]^=1,a[i.y+n-11]^=1,a[i.z+n-11]^=1;
	}
	puts("YES");
	printf("%d\n",(int)ans.size());
	for(Operation i:ans){
		printf("%d %d %d\n",i.x,i.y,i.z);
	}
	return 0;
}