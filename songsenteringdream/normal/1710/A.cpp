#include<cstdio>
using namespace std;
const int o=1e5+10;
int T,n,m,k,a[o];long long s1,s2,t1,t2;
int main(){
	for(scanf("%d",&T);T--;printf(((s1>=m&&(m%2==0||t1))||(s2>=n&&(n%2==0||t2)))?"Yes\n":"No\n"),s1=s2=t1=t2=0){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=k;++i)
			scanf("%d",&a[i]),s1+=a[i]/n*(a[i]/n>1),t1+=(a[i]/n>2),s2+=a[i]/m*(a[i]/m>1),t2+=(a[i]/m>2);
	}
	return 0;
}