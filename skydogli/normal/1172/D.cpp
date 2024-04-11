#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define piii pair<pii,pii >
#define mp make_pair
#define x first
#define y second
#define MN 1005
int n,a[MN],b[MN];
vector<piii >ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&b[i]);
	}

	for(int i=1;i<n;++i){
		if(a[i]==i&&b[i]==i)continue;
		int ma=0,mb=0;
		for(int j=i;j<=n;++j)
			if(a[j]==i)ma=j;
		for(int j=i;j<=n;++j)
			if(b[j]==i)mb=j;
		assert(ma&&mb);
		assert(i!=mb||i!=ma);
		ans.push_back(mp(mp(i,mb),mp(ma,i)));
		swap(a[ma],a[i]);
		swap(b[mb],b[i]);
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();++i){
		printf("%d %d %d %d\n",ans[i].x.x,ans[i].x.y,ans[i].y.x,ans[i].y.y);
	}
	return 0;
}