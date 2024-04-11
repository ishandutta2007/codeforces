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

int n,m,a[1444444],x,st,p[1444444],val[1444444];
set<int>S;
set<int>::iterator it;

bool de(int x){
	for(;;){
		if ((*S.begin())==x)return 0;
		it=S.find(x);
		it--;
		if (val[*it]==val[x]){
			S.erase(it);
			a[p[x]]=-abs(a[p[x]]);
			S.erase(x);
			return 1;
		}
		if (!de(*it))return 0;
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	cin >> m;
	for (int i=0;i<m;i++){
		scanf("%d",&x);
		a[x-1]*=-1;
	}
	for (int i=0;i<n;i++){
		st++;
		val[st]=abs(a[i]);
		p[st]=i;
		S.insert(st);
		if (a[i]<0){
			if (!de(st)){
				puts("NO");
				return 0;
			}
		}
	}
	while (S.size()){
		it=S.end();
		it--;
		if (!de(*it)){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (int i=0;i<n-1;i++)printf("%d ",a[i]);
	cout << a[n-1] << endl;
	return 0;

}