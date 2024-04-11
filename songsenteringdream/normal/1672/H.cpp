#include<cstdio>
#include<cmath>
using namespace std;
const int o=2e5+10;
int n,q,l[o],r[o],sp[o],b[o];char s[o];
int main(){
	scanf("%d%d%s",&n,&q,s+1);
	s[0]=s[1];s[n+1]=s[n];
	for(int i=1;i<=n;++i) if(s[i]==s[i-1]) l[i]=i;else l[i]=l[i-1];
	for(int i=n;i;--i)
		if(s[i]==s[i+1]){
			r[i]=i;sp[i]=1;
			if(i%2==l[i]%2) b[i]=(s[i]=='1'?1:-1);
		}
		else r[i]=r[i+1];
	for(int i=1;i<=n;++i) sp[i]+=sp[i-1],b[i]+=b[i-1];
	for(int x,y,ans;q--;printf("%d\n",ans)){
		scanf("%d%d",&x,&y);x=l[x];y=r[y];
		ans=(sp[y]-sp[x-1]+abs(b[y]-b[x-1]))/2;
		if((sp[y]-sp[x-1]+abs(b[y]-b[x-1]))&1) ++ans;
		else if(b[y]==b[x-1]) ++ans;
		else if((b[y]>b[x-1])^(s[x]==49)) ++ans;
	}
	return 0;
}