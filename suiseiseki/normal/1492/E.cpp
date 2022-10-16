#include <vector>
#include <cstdio>
using namespace std;
const int Maxn=250000;
int n,m;
vector<vector<int> > a;
int check(){
	int maxn=0,pos=0;
	for(int i=1;i<n;i++){
		int num=0;
		for(int j=0;j<m;j++){
			if(a[0][j]!=a[i][j]){
				num++;
			}
		}
		if(num>2&&num>maxn){
			pos=i;
		}
		maxn=max(maxn,num);
	}
	if(maxn>4){
		return -1;
	}
	return pos;
}
int v[Maxn+5];
int lis[Maxn+5],lis_len;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		vector<int> b(m);
		for(int j=0;j<m;j++){
			scanf("%d",&b[j]);
		}
		a.push_back(b);
	}
	int val=check();
	if(val==-1){
		puts("No");
		return 0;
	}
	if(val==0){
		puts("Yes");
		for(int i=0;i<m;i++){
			printf("%d ",a[0][i]);
		}
		puts("");
		return 0;
	}
	for(int i=0;i<m;i++){
		if(a[0][i]!=a[val][i]){
			lis[lis_len++]=i;
		}
	}
	if(lis_len==3){
		for(int i=0;i<3;i++){
			v[lis[i]]=a[0][lis[i]];
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i==j){
					continue;
				}
				int k=3-i-j;
				a[0][lis[j]]=a[val][lis[j]];
				int tmp=check();
				if(tmp==0){
					puts("Yes");
					for(int l=0;l<m;l++){
						printf("%d ",a[0][l]);
					}
					puts("");
					return 0;
				}
				if(tmp==-1){
					continue;
				}
				a[0][lis[k]]=a[tmp][lis[k]];
				if(check()==0){
					puts("Yes");
					for(int l=0;l<m;l++){
						printf("%d ",a[0][l]);
					}
					puts("");
					return 0;
				}
				for(int l=0;l<3;l++){
					a[0][lis[l]]=v[lis[l]];
				}
			}
		}
	}
	else{
		for(int i=0;i<(1<<4);i++){
			int num=0;
			for(int j=0;j<4;j++){
				if((i>>j)&1){
					num++;
				}
			}
			if(num!=2){
				continue;
			}
			for(int j=0;j<4;j++){
				if((i>>j)&1){
					v[lis[j]]=a[0][lis[j]];
					a[0][lis[j]]=a[val][lis[j]];
				}
			}
			if(check()==0){
				puts("Yes");
				for(int j=0;j<m;j++){
					printf("%d ",a[0][j]);
				}
				puts("");
				return 0;
			}
			for(int j=0;j<4;j++){
				if((i>>j)&1){
					a[0][lis[j]]=v[lis[j]];
				}
			}
		}
	}
	puts("No");
	return 0;
}