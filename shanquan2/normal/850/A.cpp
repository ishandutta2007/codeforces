#include<bits/stdc++.h>
using namespace std;

struct pnt{
	int a,b,c,d,e;
	pnt operator -(const pnt &o)const{
		return (pnt){a-o.a,b-o.b,c-o.c,d-o.d,e-o.e};
	}
	int operator *(const pnt &o)const{
		return a*o.a+b*o.b+c*o.c+d*o.d+e*o.e;
	}
}a[1005];
int n,cnt,ans[1005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d%d%d%d",&a[i].a,&a[i].b,&a[i].c,&a[i].d,&a[i].e);
	if(n>40){
		printf("0\n");return 0;
	}
	for(int i=0;i<n;i++){
		bool f=1;
		for(int j=0;j<n;j++)if(j!=i){
			for(int k=j+1;k<n;k++)if(k!=i)
				if((a[k]-a[i])*(a[j]-a[i])>0){f=0;break;}
			if(!f)break;
		}
		if(f)ans[cnt++]=i+1;
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)printf("%d\n",ans[i]);
	return 0;
}