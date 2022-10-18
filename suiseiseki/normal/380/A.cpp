#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 100000
struct Node{
	int s;
	ll x,y;
}xin[Maxn+5];
int n,m,num[Maxn+5],ans[Maxn+5],c,cnt;
ll k[Maxn+5];
void work(){
	c=0;
	for(int i=0;i<m;i++){
		if(xin[i].s==1){
			num[c++]=xin[i].x;
			if(c>=Maxn){
				return;
			}
		}
		else{
			for(ll t=0;t<xin[i].y;t++){
				for(ll j=0;j<xin[i].x;j++){
					num[c++]=num[j];
					if(c>=Maxn){
						return;
					}
				}
			}
		}
	}
}
void solve(){
	int i=0,j=0;
	ll p=0;
	while(i<n){
		while(j<m){
			if(xin[j].s==1){
				p++;
				j++;
				if(p==k[i]){
					ans[i]=xin[j-1].x;
					i++;
					if(i>=n){
						return;
					}
					break;
				}
			}
			else{
				ll q=p;
				p+=xin[j].x*xin[j].y;
				if(p>=k[i]){
					while(i<n){
						if(k[i]<=p){
							ans[i]=num[(k[i]-q-1)%xin[j].x%Maxn];
							i++;
							if(i>=n){
								return;
							}
						}
						else{
							j++;
							break;
						}
					}
				}
				else{
					j++;
				}
			}
		}
	}
}
int main(){
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&xin[i].s);
		if(xin[i].s==1){
			cin>>xin[i].x;
		}
		else{
			cin>>xin[i].x>>xin[i].y;
		}
	}
	work();
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	solve();
	for(int i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}