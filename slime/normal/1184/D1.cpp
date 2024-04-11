#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k,m,t,l,pl;

int main(){
	n=readint(); k=readint(); m=readint(); t=readint();
	l=n,pl=k;
	int opt,x;
	while(t--){
		opt=readint(); x=readint();
		if(opt==0){
			if(pl<=x) l=x;
			else l=l-x,pl-=x;
		}
		else{
			if(x<=pl) pl++,l++;
			else l++;
		}
		printf("%d %d\n",l,pl);
	}
	return 0;
}