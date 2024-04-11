#include<cstdio>
#include<vector>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=1<<13;
int n,ans[o],r[o],s;vector<int> g[o];
int main(){
	read(n);ans[0]=1;
	for(int i=0;i<o;++i) g[i].push_back(0),r[i]=o;
	for(int x,i,j,k;n--;g[x].clear())
		for(read(x),i=0,j=g[x].size();i<j;++i)
			for(ans[k=g[x][i]^x]=1;r[k]>x;) if(x!=--r[k]) g[r[k]].push_back(k);
	for(int i=0;i<o;++i) s+=ans[i];
	printf("%d\n",s);
	for(int i=0;i<o;++i) if(ans[i]) printf("%d ",i);
	return 0;
}