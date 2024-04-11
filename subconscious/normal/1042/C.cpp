#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2e5+5;
int a[N],n,mi,sgn;
bool on[N];
int main(){
	scanf("%d",&n);
	mi=-1;bool flag=0;
	sgn=1;
	rep(i,n){
		scanf("%d",a+i);
		if(a[i]<0)sgn=-sgn;
		if(a[i]==0)flag=1;
		else if(a[i]<0){if(mi==-1||a[mi]<a[i])mi=i;}
		on[i]=1;
	}
	if(sgn==-1)flag=1;
	int cnt=0;
	rep(i,n)if(a[i]==0)++cnt;
	if(cnt==n){
		rep(i,n-1)printf("%d %d %d\n",1,i,i+1);
		return 0;
	}
	if(cnt==n-1&&(sgn==-1)){
		int la=-1;
		rep(i,n)if(a[i]==0){
			if(la!=-1)printf("%d %d %d\n",1,la,i);
			la=i;
		}else printf("%d %d\n",2,i);
		return 0;
	}
	if(flag){
		int la=-1;
		rep(i,n)if(a[i]==0||(i==mi&&sgn==-1)){
			on[i]=0;
			if(la!=-1)printf("%d %d %d\n",1,la,i);
			la=i;
		}
		printf("%d %d\n",2,la);
	}
	int la=-1;
	rep(i,n)if(on[i]){
		if(la!=-1)printf("%d %d %d\n",1,la,i);
		la=i;
	}
	return 0;
}