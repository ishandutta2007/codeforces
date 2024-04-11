#include<bits/stdc++.h>
using namespace std;
#define MN 1000005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
int n,a[MN];
double ans[MN];
struct data{
	int l,r;
	LL sum;
	data(int L=0,int R=0,LL S=0){
		l=L;r=R;sum=S;
	}
};
stack<data>Q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;++i){
		data w=data(i,i,a[i]);
		while(!Q.empty()){
			data e=Q.top();
			int l1=e.r-e.l+1,l2=w.r-w.l+1;
			if(e.sum*l2>w.sum*l1){
				Q.pop();
				w.l=e.l;
				w.sum+=e.sum;
			}
			else break;
		}
		Q.push(w);
	}
	while(!Q.empty()){
		data e=Q.top();Q.pop();
		int l=e.l,r=e.r;
		for(int i=l;i<=r;++i)
			ans[i]=1.0*e.sum/(r-l+1);
	}
	for(int i=1;i<=n;++i)
		printf("%.10lf\n",ans[i]);
	return 0;
}