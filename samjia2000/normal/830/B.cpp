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

const int N = 100010;

int n;
int a[N];
map<int,int>id;
int k;
set<int> s[N];
int tree[N];

void add(int x,int v){
	while(x<=n){
		tree[x]+=v;
		x+=x&-x;
	}
}

int getv(int x){
	int ans=0;
	while(x){
		ans+=tree[x];
		x-=x&-x;
	}
	return ans;
}

int main(){
	n=get();
	fo(i,1,n){
		a[i]=get();
		add(i,1);
		if (id[a[i]]==0)id[a[i]]=++k;
		s[id[a[i]]].insert(i);
	}
	int now=0;
	LL ans=0;
	for(map<int,int>::iterator h=id.begin();h!=id.end();h++){
		int t=(*h).second;
		while(s[t].begin()!=s[t].end()){
			set<int>::iterator p=s[t].upper_bound(now);
			if (p!=s[t].end()){
				ans=ans-getv(now);
				now=*p;
				ans=ans+getv(now);
				add(now,-1);
				s[t].erase(p);
			}
			else{
				p=s[t].begin();
				ans=ans-getv(now);
				now=*p;
				ans=ans+getv(n)+getv(now);
				s[t].erase(p);
				add(now,-1);
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}