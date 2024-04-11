#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define M 1000000007
using namespace std;
int n,x,l,r,s=1;
set<int>B,S,U;
set<int>::iterator it;
char T[10];
int main(){
	scanf("%d",&n);
	for(;n--;){
		scanf("%s%d",T,&x);
		if(B.size())
		l=*(B.rbegin());
		else l=0;
		if(S.size())
		r=*(S.begin());
		else r=1e9;
		if(T[1]=='D'){
			if(x<=l)B.insert(x);
			else if(x>=r)S.insert(x);
			else U.insert(x);
		}
		else{
			if(x<l||x>r)return puts("0"),0;
			if(x==l){
				B.erase(x);
				for(it=U.begin();it!=U.end();it++){
					S.insert(*it);
				}
			}
			else if(x==r){
				S.erase(x);
				for(it=U.begin();it!=U.end();it++){
					B.insert(*it);
				}
			}
			else{
				U.erase(x),(s<<=1)>=M?s-=M:0;
				for(it=U.begin();it!=U.end();it++){
					if((*it)<x)B.insert(*it);
					else S.insert(*it);
				}
			}
			U.clear();
		}
	}
	s=1ll*s*(U.size()+1)%M;
	printf("%d",s);
}