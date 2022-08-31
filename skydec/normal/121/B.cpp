#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j),__tmp=k;i<=__tmp;i++)
#define per(i,j,k) for(int i=(j),__tmp=k;i>=__tmp;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 110000
char a[MAXN];int k;
int n;
void work(int l,int r){
	for(int i=l;i<r;i++){
		if(a[i]=='4'&&a[i+1]=='7'){
			if(i&1){
				a[i+1]='4';
				k--;
				if(!k){
					printf("%s",a+1);
					exit(0);
				}
				if(a[i+2]=='7'){
					k%=2;
					if(k&1){
						a[i+1]='7';
						printf("%s",a+1);
						exit(0);
					}
					else
					{
						printf("%s",a+1);
						exit(0);
					}
				}
			}
			else
			{
				a[i]='7';
				k--;
				if(!k){
					printf("%s",a+1);
					exit(0);
				}
				if(a[i-1]=='4'){
					k%=2;
					if(k&1){
						a[i]='4';
						printf("%s",a+1);
						exit(0);
					}
					else
					{
						printf("%s",a+1);
						exit(0);
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
	if(!k){
		printf("%s",a+1);
		exit(0);
	}
	for(int i=1;i<=n;i++){
		if(a[i]!='4'&&a[i]!='7')continue;
		int j=i;
		while(j<n&&(a[j+1]=='4'||a[j+1]=='7'))j++;
		work(i,j);
		i=j;
	}
	printf("%s",a+1);
	return 0;
}