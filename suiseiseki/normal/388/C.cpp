#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100
int a[Maxn+5][Maxn+5];
int len[Maxn+5];
int n;
int x[Maxn+5],sz;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	scanf("%d",&n);
	int ans_1=0,ans_2=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		for(int j=1;j<=len[i];j++){
			scanf("%d",&a[i][j]);
		}
		if(len[i]&1){
			for(int j=1;j<=(len[i]>>1);j++){
				ans_1+=a[i][j];
			}
			for(int j=(len[i]>>1)+2;j<=len[i];j++){
				ans_2+=a[i][j];
			}
			x[++sz]=a[i][(len[i]+1)>>1];
		}
		else{
			for(int j=1;j<=(len[i]>>1);j++){
				ans_1+=a[i][j];
			}
			for(int j=(len[i]>>1)+1;j<=len[i];j++){
				ans_2+=a[i][j];
			}
		}
	}
	sort(x+1,x+1+sz,cmp);
	for(int i=1;i<=sz;i++){
		if(i&1){
			ans_1+=x[i];
		}
		else{
			ans_2+=x[i];
		}
	}
	printf("%d %d\n",ans_1,ans_2);
	return 0;
}