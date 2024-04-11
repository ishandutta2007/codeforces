#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<bitset>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
bitset<1250010>bt[26];
int n;
int a[55];
int main(){
	n=read();
	for(int i=1;i<=2*n;++i) a[i]=read();
	sort(a+1,a+2*n+1);
	int sum=0;
	for(int i=3;i<=2*n;++i) sum+=a[i];
	bt[0][0]=1;
	for(int i=3;i<=2*n;++i){
		for(int j=n-1;j>=1;--j) bt[j]|=(bt[j-1]<<a[i]);
	}
	int ans=1e9;
	for(int i=0;i<=sum;++i) if(bt[n-1][i]){
		ans=min(ans,max(i,sum-i));
	}
	int tmp=ans,nw=n-1;
	vector<int>a1,a2;
	for(int i=2*n;i>=3;--i){
		if(nw==0||tmp-a[i]<0) a2.pb(a[i]);
		else{
			if(bt[nw-1][tmp-a[i]]) a1.pb(a[i]),tmp-=a[i],--nw;
			else a2.pb(a[i]);
		}
	}
	sort(a1.begin(),a1.end());
	printf("%d ",a[1]);for(int i:a1) printf("%d ",i);printf("\n");
	for(int i:a2) printf("%d ",i);printf("%d\n",a[2]);
}