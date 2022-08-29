#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define y1 FFF
using namespace std;
const int N=100005;
int n,m,cl,ce,v;
int l[N],e[N];
int q,x1,x2,y1,y2;
int main(){
	scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
	rep(i,cl)scanf("%d",l+i);sort(l+1,l+cl+1);
	rep(i,ce)scanf("%d",e+i);sort(e+1,e+ce+1);
	scanf("%d",&q);
	rep(i,q){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1>x2)swap(x1,x2);if(y1>y2)swap(y1,y2);
		swap(x1,y1);swap(x2,y2);
		int tl=lower_bound(l+1,l+cl+1,x1)-l,
			te=lower_bound(e+1,e+ce+1,x1)-e;
		int ans=0x3f3f3f3f;
		if(tl<=cl)ans=min(ans,abs(x1-l[tl])+y2-y1+abs(x2-l[tl]));
		//printf("%d\n",ans);

		if(tl>1)ans=min(ans,abs(x1-l[tl-1])+y2-y1+abs(x2-l[tl-1]));
		//printf("%d\n",ans);
		if(te<=ce)ans=min(ans,abs(x1-e[te])+(y2-y1)/v+((y2-y1)%v!=0)+abs(x2-e[te]));
		//printf("%d\n",ans);
		if(te>1)ans=min(ans,abs(x1-e[te-1])+(y2-y1)/v+((y2-y1)%v!=0)+abs(x2-e[te-1]));
		if(y2==y1)ans=min(ans,x2-x1);
		//printf("%d\n",ans);
		printf("%d\n",ans);
	}
	//system("pause");
	return 0;
}