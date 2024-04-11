#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e5+10;
int T,n,m,a[o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d%d",&n,&m);ans=m;
		for(int i=1;i<=m;++i) scanf("%d",&a[i]);
		sort(a+1,a+m+1);a[m+1]=a[1]+n;
		for(int i=1;i<=m;++i) a[i]=a[i+1]-a[i]-1;
		sort(a+1,a+m+1);
		for(int i=m,j=0;i;--i){
			if(a[i]>2*j){
				a[i]-=2*j;ans+=2*j;++j;
				if(--a[i]){
					++ans;
					if(--a[i]) ++j;
				}
			}
			else ans+=a[i];
		}
	}
	return 0;
}