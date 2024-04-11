#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
set<int>s;
vector<int>v;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		s.clear(),v.clear();
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			if(a[i]<=n&&!s.count(a[i]))s.insert(a[i]);
			else v.push_back((a[i]-1)/2);
		}
		sort(v.begin(),v.end(),greater<int>());
		for(ri i=1;i<=n;++i)
			if(!s.count(i)){
				if(v.back()<i){
					puts("-1");
					goto skip;
				}
				else v.pop_back();
			}
		printf("%d\n",n-(int)s.size());
		skip:;
	}
	return 0;
}