#include<bits/stdc++.h>
using namespace std;
#define MN 200005
int T,n,m;
char ch[MN];
int main(){
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d%d%s",&n,&x,ch+1);
		int cnt=0;
		int ans=0;
		if(x==0) ++ans;
		for(int i=1;i<=n;++i){
			if(ch[i]=='0')++cnt;
			else --cnt;
		}
		int now=0,op=1;;
		for(int i=1;i<=n;++i){
			if(ch[i]=='0') ++now;
			else now--;
			int w=x-now;
			if(w==0&&cnt==0){puts("-1");op=0;break;}
			if(cnt!=0&&abs(w)%abs(cnt)==0&&w/cnt>=0) ans++;
		}
		if(op)printf("%d\n",ans);
	}
}