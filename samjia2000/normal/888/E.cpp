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

const int N = 40;

int a[N];
int n,m;
int mx,ans;
set<int>s;

int add(int x,int y){return x+y>=m?x+y-m:x+y;}

void solvel(int x,int v){
	if (x>n/2){
		mx=max(mx,v);
		s.insert(v);
		return;
	}
	solvel(x+1,v);
	solvel(x+1,add(v,a[x]));
}

void solver(int x,int v){
	if (x>n){
		ans=max(ans,add(v,mx));
		set<int>::iterator h=s.lower_bound(m-v);
		if (h!=s.end()&&h!=s.begin()){
			h--;
			ans=max(ans,add(v,*h));
		}
		return;
	}
	solver(x+1,v);
	solver(x+1,add(v,a[x]));
}

int main(){
	n=get();m=get();
	fo(i,1,n)a[i]=get()%m;
	ans=0;
	solvel(1,0);
	solver(n/2+1,0);
	printf("%d\n",ans);
	return 0;
}