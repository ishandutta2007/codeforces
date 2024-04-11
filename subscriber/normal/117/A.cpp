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
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;


int n,m,a,b,t;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	m--;
	for (int i=0;i<n;i++){
		scanf("%d%d%d",&a,&b,&t);
		if (a==b){
			printf("%d\n",t);
			continue;
		}
		a--;
		b--;
		int o=1,ans;
		if (t%(m+m)>m)o=0;
		int c=t%(m+m);
		if (c>m-1)c=m-1-(c-m-1);
		if (o){
			if (c<=a)ans=t+a-c;else ans=t+m+m-a-c,o^=1;
		}else{
			if (c>=a)ans=t+c-a;else ans=t+a+c,o^=1;
		}
		if (o){
			if (a<=b)ans+=b-a;else ans+=m+m-a-b;
		}else{
			if (a>=b)ans+=a-b;else ans+=a+b;
		}
		printf("%d\n",ans);
		
	}
	return 0;
}