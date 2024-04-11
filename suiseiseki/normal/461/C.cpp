#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 100000
ll C[Maxn+5];
int n,q;
void add(int x,ll v){
	for(;x<=n;x+=x&-x){
		C[x]+=v;
	}
}
ll sum(int x){
	ll res=0;
	for(;x>0;x-=x&-x){
		res+=C[x];
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		add(i,1);
	}
	int s=1,t=n,l,r,type;
	int flip=0;
	ll val;
	while(q--){
		scanf("%d",&type);
		if(type==1){
			scanf("%d",&l);
			if(flip){
				if((l<<1)>(t-s+1)){
					flip^=1;
					l=t-s+1-l;
					for(int i=1;i<=l;i++){
						val=sum(s+l-i)-sum(s+l-i-1);
						add(s+l+i-1,val);
					}
					s+=l;
				}
				else{
					for(int i=1;i<=l;i++){
						val=sum(t-i+1)-sum(t-i);
						add(t-(l<<1)+i,val);
					}
					t-=l;
				}
			}
			else{
				if((l<<1)>(t-s+1)){
					flip^=1;
					l=t-s+1-l;
					for(int i=1;i<=l;i++){
						val=sum(t-i+1)-sum(t-i);
						add(t-(l<<1)+i,val);
					}
					t-=l;
				}
				else{
					for(int i=1;i<=l;i++){
						val=sum(s+l-i)-sum(s+l-i-1);
						add(s+l+i-1,val);
					}
					s+=l;
				}
			}
		}
		else{
			scanf("%d%d",&l,&r);
			if(!flip){
				r--;
				l+=s;
				r+=s;
				val=sum(r)-sum(l-1);
			}
			else{
				int R=t-l;
				int L=t-r+1;
				val=sum(R)-sum(L-1);
			}
			cout<<val<<endl;
		}
	}
	return 0;
}