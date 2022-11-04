#include<set>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,p[200010],a[200010],b[200010];
int m,c[200010];
set<pair<int,int> > S[4];
bool chosed[200010];
inline int answer(int x){
	while(1){
		if(S[x].size()==0) return -1;
		int ret=S[x].begin()->second;
		S[x].erase(S[x].begin());
		if(!chosed[ret]){
			chosed[ret]=1;
			return p[ret];
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",p+i);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	for(int i=0;i<n;++i) scanf("%d",b+i);
	for(int i=0;i<n;++i){
		S[a[i]].insert(make_pair(p[i],i));
		S[b[i]].insert(make_pair(p[i],i));
	}
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		scanf("%d",c+i);
		printf("%d%c",answer(c[i]),i==m-1?'\n':' ');
	}
	return 0;
}