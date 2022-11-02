#include<bits/stdc++.h>
const int N=200005;
using namespace std;
int n,m,a[N],b[N],c[N],loc[N],mn;
vector<int>ch[N];
int main(){
	scanf("%d",&n);
	if(n==1)return puts("1 2"),0;
	for(int i=0;i<n;i++)
	scanf("%d",a+i),c[i]=i;
	sort(c,c+n,[](int x,int y){return a[x]>a[y];});
	m=n>>1;
	for(int i=0;i<n;i++)
	if(i<m)b[i]=c[i];else b[n-(i-m)-1]=c[i];
	for(int i=0;i<n;i++){
		ch[i].push_back(2*b[i]+1);
		if(i)printf("%d %d\n",2*b[i-1]+1,2*b[i]+1);
	}
	for(int i=0;i<m;i++){
		loc[i]=i+a[b[i]]-1;
		if(loc[i]>n-1)loc[i]=loc[i-1];
		mn=a[b[i]]-(loc[i]-i)-1;
		//cerr<<loc[i]<<'/'<<mn<<endl;
		printf("%d %d\n",2*b[i]+2,ch[loc[i]][mn]);
		if(mn+1==ch[loc[i]].size())
		ch[loc[i]].push_back(2*b[i]+2);
	}
	for(int i=n-1;i>=m;i--){
		loc[i]=i-a[b[i]]+1;
		if(loc[i]<0)loc[i]=loc[i+1];
		mn=a[b[i]]-(i-loc[i])-1;
		//cerr<<loc[i]<<'/'<<mn<<endl;
		printf("%d %d\n",2*b[i]+2,ch[loc[i]][mn]);
		if(mn+1==ch[loc[i]].size())
		ch[loc[i]].push_back(2*b[i]+2);
	}
}