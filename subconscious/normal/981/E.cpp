#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=1e4+5;
typedef long long ll;
int a[N];
int n,q,P;
vector<int>Q[N];
int l,r,x;
bool ans[N];
int main(){
	srand(time(0));int tp=rand()%5;
	if(tp==0)P=1e9+7;
	else if(tp==1)P=1e9+9;
	else if(tp==2)P=1e9+21;
	else if(tp==3)P=1e9+33;
	else P=1e9+87;
	scanf("%d%d",&n,&q);
	rep(i,q)scanf("%d%d%d",&l,&r,&x),Q[l].push_back(x),Q[r+1].push_back(-x);
	a[0]=1;
	rep(cur,n){
		for(int i=0;i<Q[cur].size();++i)if(Q[cur][i]>0){
			x=Q[cur][i];
			for(int j=n-x;~j;--j)a[j+x]=(a[j+x]+a[j])%P;
		}else{
			x=-Q[cur][i];
			for(int j=x;j<=n;++j)a[j]=(a[j]-a[j-x]+P)%P;
		}
		//rep(j,n)printf("%d ",a[j]);puts("");
		rep(j,n)ans[j]|=(a[j]>0);
	}
	int ss=0;
	rep(i,n)if(ans[i])++ss;
	printf("%d\n",ss);
	rep(i,n)if(ans[i])printf("%d%c",i,!(--ss)?'\n':' ');
	//system("pause");
	return 0;
}