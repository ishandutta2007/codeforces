#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 300000
#define Mod 998244353
#define ll long long
int n;
struct Node{
	int x,y;
	friend bool operator <(Node p,Node q){
		if(p.x==q.x){
			return p.y<q.y;
		}
		return p.x<q.x;
	}
}a[Maxn+5];
ll fac[Maxn+5];
bool cmp(Node p,Node q){
	return p.y<q.y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%Mod;
	}
	sort(a+1,a+1+n);
	ll ans_1=1,ans_2=1,ans_3=1,ans_4=1;
	for(int i=1;i<n;i++){
		if(a[i].y>a[i+1].y){
			ans_4=0;
			break;
		}
	}
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(a[i].x==a[j].x&&j<=n){
			j++;
		}
		j--;
		ans_2*=fac[j-i+1];
		ans_2%=Mod;
		if(ans_4!=-1){
			for(int k=i,l;k<=j;k=l+1){
				l=k;
				while(a[k].y==a[l].y&&l<=j){
					l++;
				}
				l--;
				ans_4*=fac[l-k+1];
				ans_4%=Mod;
			}
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(a[i].y==a[j].y&&j<=n){
			j++;
		}
		j--;
		ans_3*=fac[j-i+1];
		ans_3%=Mod;
	}
	ans_2+=ans_3;
	ans_2-=ans_4;
	ans_2%=Mod;
	ans_2+=Mod;
	ans_2%=Mod;
	ans_1=fac[n];
	ans_1-=ans_2;
	ans_1%=Mod;
	ans_1+=Mod;
	ans_1%=Mod;
	cout<<ans_1<<endl;
	return 0;
}