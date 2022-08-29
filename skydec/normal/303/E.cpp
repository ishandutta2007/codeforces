//orz YJN
//
//
//
//IGM
//
//
//
//
//
//Orz Orz Orz Orz Orz
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int n;int l[105],r[105];int q[205];
db f[105][105];db ans[105];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&l[i],&r[i]);
	rep(i,1,n){
		q[++q[0]]=l[i];
		q[++q[0]]=r[i];
	}
	sort(q+1,q+1+q[0]);
	int N=unique(q+1,q+1+q[0])-q-1;
	rep(i,1,n){
		memset(ans,0,sizeof ans);
		rep(j,1,N-1)if(q[j]<r[i]&&q[j]>=l[i]){
			int L,R;
			L=q[j];R=q[j+1];
			int gt=0;memset(f,0,sizeof f);
			f[0][0]=1;int fu=0;
			rep(k,1,n)if(k!=i){
				if(r[k]<=L){
					fu++;
					continue;
				}
				if(l[k]>=R)continue;
				//    L...R
				// l[k].....r[k]
				int len=r[k]-l[k];
				db front=(L-l[k])*1./len;
				db in=(R-L)*1./len;
				// f[x][y]: x is front ,y is in
				per(x,gt,0)per(y,gt-x,0){
					f[x+1][y]+=f[x][y]*front;
					f[x][y+1]+=f[x][y]*in;
					f[x][y]*=(1-front-in);
				}
				gt++;
			}
			db tmp=1.*(R-L)/(r[i]-l[i]);
			rep(x,0,gt)rep(y,0,gt)if(f[x][y]>1e-12)
			rep(k,x+1+fu,x+1+y+fu)ans[k]+=f[x][y]*tmp/(y+1);
		}
		rep(j,1,n)printf("%.10lf%c",ans[j],j==n?'\n':' ');
	}
	return 0;
}