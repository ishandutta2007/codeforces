#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
const int Inf=0x3f3f3f3f;
int n,T,s,d;
int a[Maxn+5];
int dis[Maxn+5];
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> >,std::greater<std::pair<int,int> > > q;
std::set<int> st,pos;
int find_val(int x){
	std::set<int>::iterator it=pos.lower_bound(x);
	int ans=Inf;
	if(it!=pos.end()){
		ans=std::min(ans,std::abs(x-(*it)));
	}
	if(it!=pos.begin()){
		it--;
		ans=std::min(ans,std::abs(x-(*it)));
	}
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&T,&s,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		st.insert(i);
	}
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	q.push(std::make_pair(0,s));
	while(!q.empty()){
		std::pair<int,int> cur_u=q.top();
		q.pop();
		if(dis[cur_u.second]!=cur_u.first){
			continue;
		}
		int u=cur_u.second;
		st.erase(u);
		int v=a[u]-d;
		pos.insert(v);
		int tmp_v=std::lower_bound(a+1,a+1+n,v)-a;
		std::set<int>::iterator it=st.lower_bound(tmp_v);
		if(it!=st.end()){
			int val=std::max(dis[u],std::abs(a[*it]-v));
			if(val<dis[*it]){
				dis[*it]=val;
				q.push(std::make_pair(val,*it));
			}
		}
		if(it!=st.begin()){
			it--;
			int val=std::max(dis[u],std::abs(a[*it]-v));
			if(val<dis[*it]){
				dis[*it]=val;
				q.push(std::make_pair(val,*it));
			}
		}
		v=a[u]+d;
		pos.insert(v);
		tmp_v=std::lower_bound(a+1,a+1+n,v)-a;
		it=st.lower_bound(tmp_v);
		if(it!=st.end()){
			int val=std::max(dis[u],std::abs(a[*it]-v));
			if(val<dis[*it]){
				dis[*it]=val;
				q.push(std::make_pair(val,*it));
			}
		}
		if(it!=st.begin()){
			it--;
			int val=std::max(dis[u],std::abs(a[*it]-v));
			if(val<dis[*it]){
				dis[*it]=val;
				q.push(std::make_pair(val,*it));
			}
		}
		it=st.lower_bound(u);
		if(it!=st.end()){
			int val=std::max(dis[u],find_val(a[*it]));
			if(val<dis[*it]){
				dis[*it]=val;
				q.push(std::make_pair(val,*it));
			}
		}
		if(it!=st.begin()){
			it--;
			int val=std::max(dis[u],find_val(a[*it]));
			if(val<dis[*it]){
				dis[*it]=val;
				q.push(std::make_pair(val,*it));
			}
		}
	}
	for(int t=1;t<=T;t++){
		int x,k;
		scanf("%d%d",&x,&k);
		if(k>=dis[x]){
			puts("Yes");
		}
		else{
			puts("No");
		}
	}
	return 0;
}