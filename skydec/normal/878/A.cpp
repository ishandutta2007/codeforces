#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=510000;
char op[N][5];
int a[N];
int n;
int ad,oo,xx;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",op[i]+1);
		scanf("%d",&a[i]);
	}
	per(i,9,0){
		int w[2];w[0]=0;w[1]=1;
		rep(j,1,n){
			int c=((a[j]&(1<<i))>0);
			rep(k,0,1){
				if(op[j][1]=='^')w[k]^=c;
				if(op[j][1]=='|')w[k]|=c;
				if(op[j][1]=='&')w[k]&=c;
			}
		}
		if(w[0]==0&&w[1]==1){
			ad|=(1<<i);
		}
		else
		if(w[0]==1&&w[1]==0){
			ad|=(1<<i);
			xx|=(1<<i);
		}
		else
		if(w[0]+w[1]){
			oo|=(1<<i);
		}
		else{

		}
	}
	printf("3\n");
	printf("^ %d\n",xx);
	printf("& %d\n",ad);
	printf("| %d\n",oo);
	return 0;
}