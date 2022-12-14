#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,d[N],id[N],dep[2*N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",d+i),id[i]=i;
	sort(id+1,id+1+n,[](int x,int y){return d[x]>d[y];});
	vector<int> v;
	for(int i=1;i<=n;++i)v.push_back(2*id[i]-1);
	for(int i=2;i<=n;++i)printf("%d %d\n",2*id[i-1]-1,2*id[i]-1);
	for(int i=1;i<=n;++i)
		if(i+d[id[i]]-2==(int)v.size())
			printf("%d %d\n",v.back(),2*id[i]),v.push_back(2*id[i]);
		else{
			printf("%d %d\n",v[i+d[id[i]]-2],2*id[i]);
			if(i+d[id[i]]-2==(int)v.size()-1)v.push_back(2*id[i]);
		}
}