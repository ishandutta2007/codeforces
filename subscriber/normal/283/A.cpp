#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int k,n,t,x,y;
long long s[555555],sum=0;

void add(int x,int v){
	while (x<=444444){
		s[x]+=v;
		x=x+x-(x&(x-1));
	}
}

long long find(int x){
	long long r=0;
	while (x){
		r+=s[x];
		x&=x-1;
	}
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> k;
	n=1;
	for (int i=0;i<k;i++){
		scanf("%d",&t);
		if (t==2){
			scanf("%d",&x);
			n++;
			sum+=x;
			add(n,x);
			add(n+1,-x);
		}else if (t==1){
			scanf("%d%d",&x,&y);
			sum+=x*1ll*y;
			add(1,y);
			add(x+1,-y);
		}else{
			long long e=find(n);
			sum-=e;
			add(n,-e);
			add(n+1,e);
			n--;
		}
		printf("%.10lf\n",sum/1./n);
	}
	return 0;
}