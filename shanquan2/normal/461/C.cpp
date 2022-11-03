#include<cstdio>
using namespace std;

int now,s=0,a[100010];
bool rev=0;
int main(){
	int n,q;scanf("%d%d",&n,&q);
	for(int i=0;i<=n;i++)a[i]=i;
	now=n;
	for(int i=0;i<q;i++){
		int c;scanf("%d",&c);
		if(c==1){
			int x;scanf("%d",&x);
			if((x<<1)>now){
				rev=!rev;
				x=now-x;
			}
			if(rev){
				for(int i=now-2*x+1;i<=now-x;i++)
					a[s+i]+=n-a[s+2*now-2*x-i];
			}else{
				for(int i=x+1;i<=2*x;i++)
					a[s+i]-=a[s+2*x-i];
				a[s+x]=0;s+=x;
			}
			now-=x;
//			for(int i=0;i<=now;i++)printf("%d ",a[s+i]);printf("\n");
		}else{
			int x,y;scanf("%d%d",&x,&y);
			if(rev){
				x=now-x,y=now-y;
				int t=x;x=y;y=t;
			}
			printf("%d\n",a[s+y]-a[s+x]);
		}
	}
	return 0;
}