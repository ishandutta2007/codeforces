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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,m,x,t,f[111111],b;
set<int>v[111111];
char o;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<m;i++){
		scanf("%c%d\n",&o,&x);
		t=x;
		if (o=='-'){
			if (!f[x]){
				puts("Already off");
				continue;
		       	}
			puts("Success");
			f[x]=0;
			for (int j=2;j*j<=x;j++)if (x%j==0){
				v[j].erase(t);
				while (x%j==0)x/=j;
			}
			if (x>1){
				v[x].erase(t);
			}
		}else{
			if (f[x]){
				puts("Already on");
				continue;
			}	
			b=-1;
			for (int j=2;j*j<=x;j++)if (x%j==0){
				if (v[j].size())b=*(v[j].begin());
				while (x%j==0)x/=j;
			}
			if (x>1){
				if (v[x].size())b=*(v[x].begin());
			}
			if (b!=-1){
				cout << "Conflict with " << b << endl;
				continue;
			}
			puts("Success");
			f[t]=1;
			x=t;
			for (int j=2;j*j<=x;j++)if (x%j==0){
				v[j].insert(t);
				while (x%j==0)x/=j;
			}
			if (x>1){
				v[x].insert(t);
			}
		}
	}
	return 0;
}