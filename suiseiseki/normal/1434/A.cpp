#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=100000;
const int Inf=0x3f3f3f3f;
int a[10],b[Maxn+5];
int n,m=6;
int f[10][Maxn+5];
int d[Maxn*10+5],d_len;
pair<int,int> id[Maxn*10+5];
int id_len;
int pos[Maxn+5];
bool cmp(pair<int,int> p,pair<int,int> q){
	if(b[p.first]-a[p.second]==b[q.first]-a[q.second]){
		if(p.first==q.first){
			return p.second>q.second;
		}
		return p.first<q.first;
	}
	return b[p.first]-a[p.second]<b[q.first]-a[q.second];
}
multiset<int> st;
void erase(int x){
	st.erase(st.find(x));
}
int main(){
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+m);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		for(int j=1;j<=m;j++){
			d[++d_len]=b[i]-a[j];
			id[++id_len].first=i;
			id[id_len].second=j;
		}
		pos[i]=6;
		st.insert(b[i]-a[m]);
	}
	sort(b+1,b+1+n);
	sort(d+1,d+1+d_len);
	d_len=unique(d+1,d+1+d_len)-d-1;
	sort(id+1,id+1+id_len,cmp);
	int ans=Inf;
	bool flag=1;
	for(int i=1,j=1;i<=d_len;i++){
		while(j<=id_len&&b[id[j].first]-a[id[j].second]<d[i]){
			erase(b[id[j].first]-a[pos[id[j].first]]);
			pos[id[j].first]--;
			if(pos[id[j].first]<1){
				flag=0;
				break;
			}
			st.insert(b[id[j].first]-a[pos[id[j].first]]);
			j++;
		}
		if(!flag){
			break;
		}
		ans=min(ans,(*--st.end())-d[i]);
	}
	printf("%d\n",ans);
	return 0;
}