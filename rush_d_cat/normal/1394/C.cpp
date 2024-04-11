#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
int n;
char s[N];
vector< pair<int,int> > vec;
int y;
pair<int,int> getin(int x,int lim,pair<int,int> p){
	int d=abs(x-p.first);
	if(d>lim)return make_pair(1e9,-1e9);
	if(p.first<=x){
		int lef=max(p.second-(lim-d),0);
		int rig=p.second+lim;
		return make_pair(lef,rig);
	}
	int lef=max(p.second-lim,0);
	int rig=p.second+lim-d;
	return make_pair(lef,rig);
}
int cal(int x){
	int lef=-1,rig=1e6;
	while(rig-lef>1){
		int mid=(lef+rig)>>1;
		int mx=-1e9,mn=1e9;
		//printf("mid=%d\n", mid);
		for(auto p:vec) {
			pair<int,int> tmp=getin(x,mid,p);

			mx=max(mx,tmp.first);
			mn=min(mn,tmp.second);
			//printf("[%d,%d] [%d,%d]\n", p.first, p.second, tmp.first,tmp.second);
		}
		//printf("mid=%d, [%d,%d]\n", mid,mx,mn);
		if(mx<=mn){
			rig=mid;
			y=mx;
		}else{
			lef=mid;
		}
	}
	//printf("y=%d\n", y);
	//printf("lef=%d\n", lef);
	return rig;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		int c1=0,c2=0;
		for(int j=0;s[j];j++){
			if(s[j]=='B')c1++;
			else c2++;
		}
		vec.push_back(make_pair(c1,c2));
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(auto p:vec){
		//printf("%d %d\n", p.first,p.second);
	} 
	//printf("-------------\n");
	int lef=0,rig=500000+10;
	//cal(4);return 0;
	//printf("ok\n");
	while(rig-lef>12){
		int midL=(lef+rig)/2;
		int midR=(midL+rig)/2;
		if(cal(midL)<=cal(midR)){
			rig=midR;
		}else{
			lef=midL;
		}
	}
	int bst=0,ans=1e9;
	//printf("lef=%d,rig=%d\n", lef,rig);
	for(int i=lef;i<=rig;i++){
		int tmp=cal(i);
		if(tmp<=ans){
			ans=tmp;
			bst=i;
		}
	}
	//printf("bst=%d\n", bst);
	cal(bst);
	printf("%d\n", ans);
	for(int i=1;i<=bst;i++)printf("B");
	for(int i=1;i<=y;i++)printf("N");
	printf("\n");
}