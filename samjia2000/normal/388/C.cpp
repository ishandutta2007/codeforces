#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 110;

int n;
int val[N];
int ans0,ans1;

int main(){
	n=get();
	int n_=0;
	fo(i,1,n){
		int k=get();
		if (k%2==0){
			fo(j,1,k/2)ans0+=get();
			fo(j,1,k/2)ans1+=get();
		}
		else{
			fo(j,1,k/2)ans0+=get();
			val[++n_]=get();
			fo(j,1,k/2)ans1+=get();
		}
	}
	n=n_;
	sort(val+1,val+1+n);
	fo(i,1,n/2)swap(val[i],val[n-i+1]);
	fo(i,1,n)
	if (i%2)ans0+=val[i];else ans1+=val[i];
	printf("%d %d\n",ans0,ans1);
	return 0;
}