#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		map<int,int>deg;
		deg[0]=1;
		for(ri i=2,f;i<=n;++i)scanf("%d",&f),++deg[f];
		vector<int>v;
		for(const auto &i:deg)v.push_back(i.second);
		sort(v.begin(),v.end());
		priority_queue<int>q;
		for(ri i=0;i<v.size();++i)q.push(v[i]-i-1);
		int ans=v.size(),lim=0;
		while(q.top()>lim){
			++ans,++lim;
			q.push(q.top()-1),q.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}