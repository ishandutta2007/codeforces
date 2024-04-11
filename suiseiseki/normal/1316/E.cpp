#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=100000;
const int Maxk=7;
typedef long long ll;
int n;
int p,k;
struct Node{
	int s[Maxk+5];
	int val;
	friend bool operator <(Node p,Node q){
		return p.val>q.val;
	}
}a[Maxn+5];
int num[Maxn+5];
int bit_count(int x){
	int ans=0;
	while(x){
		ans++;
		x-=(x&(-x));
	}
	return ans;
}
ll f[Maxn+5][(1<<Maxk)+5];
int main(){
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);
	}
	for(int i=0;i<(1<<p);i++){
		num[i]=bit_count(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<p;j++){
			scanf("%d",&a[i].s[j]);
		}
	}
	memset(f,-0x3f,sizeof f);
	sort(a+1,a+1+n);
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<p);j++){
			if(i-bit_count(j)<=k){
				f[i][j]=max(f[i][j],f[i-1][j]+a[i].val);
			}
			else{
				f[i][j]=max(f[i][j],f[i-1][j]);
			}
			for(int l=0;l<p;l++){
				if((j>>l)&1){
					int last=j^(1<<l);
					f[i][j]=max(f[i][j],f[i-1][last]+a[i].s[l]);
				}
			}
		}
	}
	cout<<f[n][(1<<p)-1]<<endl;
	return 0;
}