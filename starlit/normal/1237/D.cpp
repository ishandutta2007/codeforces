#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int n,a[N],no[N],rt[N],ans[N];
set<int>S;
set<int>::iterator it;
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",a+i),rt[i]=n*5,no[i]=i;
	sort(no,no+n,cmp);
	for(int i=0,j=0;i<n;i++){
		for(;j<n&&a[no[j]]*2<a[no[i]];j++)
		S.insert(no[j]),S.insert(no[j]+n);
		it=S.upper_bound(no[i]);
		if(it!=S.end())
		rt[no[i]]=*it;
	}
	if(a[no[0]]*2>=a[no[n-1]]){
		for(int i=0;i<n;i++)
		printf("-1 ");
		return 0;
	}
	ans[n]=n*5;
	for(int i=0;i<n;i++)
	ans[n]=min(ans[n],rt[i]+n);
	for(int i=n-1;~i;i--)
	ans[i]=min(ans[i+1],rt[i]);
	for(int i=0;i<n;i++)
	printf("%d ",ans[i]-i);
}