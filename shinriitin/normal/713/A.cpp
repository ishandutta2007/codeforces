#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;

ll gint(){
	char c; int f=1;
	while(c=getchar(),c<48||c>57)
		if(c=='-')f=-1;
	ll x=0;
	for(;c>47&&c<58;c=getchar()){
		x=x*10+c-48;
	}
	return x*f;
}

int n,cnt[1<<18];

int trans(ll x){
	int r=0;
	for(int i=1;x;x/=10,i<<=1)
		if(x&1)r^=i;
	return r;
}

int main(){
	n=gint();
	for(int i=1;i<=n;++i){
		char c;
		while(c=getchar(),c!='+'&&c!='-'&&c!='?');
		ll x=gint();
		if(c=='+'){
			++cnt[trans(x)];
		}
		else if(c=='-'){
			--cnt[trans(x)];
		}
		else{
			printf("%d\n",cnt[trans(x)]);
		}
	}
	return 0;
}