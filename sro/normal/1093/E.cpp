/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define loop(i,n) for(int i=0;i<(n);i++)
#define cont(i,n) for(int i=1;i<=(n);i++)
#define circ(i,a,b) for(int i=(a);i<=(b);i++)
#define range(i,a,b,c) for(int i=(a);((c)>0?i<=(b):i>=(b));i+=(c))
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(),_e_D_=(v).end();it!=_e_D_;it++)
#define y0 y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1 y1II11II11III11I1III11II111IIII1II1I1
#define pub push_back
#define pob pop_back
#define mak make_pair

typedef long long ll;
typedef long double lf;
const int Inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int n,m;
int a[1<<18],b[1<<18],p[1<<18],pos[1<<18];
const int bs=545,fn=399;
int bit[400][1<<18];

void inline add(int a,int to,int x){
	a=a/bs+1;
	for(int i=a;i<=fn;i+=i&-i)
		for(int j=to;j<=n;j+=j&-j)
			bit[i][j]+=x;
}

int inline sum(int a,int to){
	int b=a/bs,res=0;
	circ(i,max(1,b*bs),a)if(p[i]<=to)res++;
	for(int i=b;i;i-=i&-i)
		for(int j=to;j;j-=j&-j)
			res+=bit[i][j];
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	cont(i,n)scanf("%d",a+i),pos[a[i]]=i;
	cont(i,n)scanf("%d",b+i),p[i]=pos[b[i]],add(i,p[i],1);
	while(m--){
		int mode;scanf("%d",&mode);
		if(mode==1){
			int al,ar,bl,br;scanf("%d%d%d%d",&al,&ar,&bl,&br);
			printf("%d\n",sum(br,ar)-sum(br,al-1)-sum(bl-1,ar)+sum(bl-1,al-1));
		}else{
			int x,y;scanf("%d%d",&x,&y);
			add(x,p[x],-1);add(y,p[y],-1);
			swap(p[x],p[y]);
			add(x,p[x],1);add(y,p[y],1);
		}
	}
	return 0;
}