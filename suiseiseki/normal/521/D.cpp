#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
typedef long long ll;
const int Maxn=100000;
int a[Maxn+5];
int k,n,m;
int op[Maxn+5];
vector<pair<int,int> > q[Maxn+5][3];
int id[Maxn+5],len;
vector<pair<double,int> > b;
bool cmp(int p,int q){
	if(op[p]==op[q]){
		return p<q;
	}
	return op[p]<op[q];
}
int main(){
	read(k),read(n),read(m);
	for(int i=1;i<=k;i++){
		read(a[i]);
	}
	for(int i=1;i<=n;i++){
		read(op[i]);
		int pos;
		read(pos);
		int x;
		read(x);
		q[pos][op[i]-1].push_back(make_pair(x,i));
	}
	for(int i=1;i<=k;i++){
		if(!q[i][0].empty()){
			sort(q[i][0].begin(),q[i][0].end());
			if(q[i][0].back().first>a[i]){
				q[i][1].push_back(make_pair(q[i][0].back().first-a[i],q[i][0].back().second));
			}
		}
		if(!q[i][1].empty()){
			sort(q[i][1].begin(),q[i][1].end(),greater<pair<int,int> >());
			ll sum=a[i];
			for(int j=0;j<(int)q[i][1].size();j++){
				b.push_back(make_pair(1.0*(sum+q[i][1][j].first)/sum,q[i][1][j].second));
				sum+=q[i][1][j].first;
			}
		}
		if(!q[i][2].empty()){
			for(int j=0;j<(int)q[i][2].size();j++){
				b.push_back(make_pair(1.0*q[i][2][j].first,q[i][2][j].second));
			}
		}
	}
	sort(b.begin(),b.end(),greater<pair<double,int> >());
	for(int i=0;i<m&&i<(int)b.size();i++){
		id[++len]=b[i].second;
	}
	sort(id+1,id+1+len,cmp);
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		printf("%d ",id[i]);
	}
	puts("");
	return 0;
}