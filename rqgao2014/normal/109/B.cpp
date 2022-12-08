#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int a[1000005],c[20],tot,pl,pr,vl,vr,k;
long long ans=0;

int main()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<=i;j++)
			c[j]=0;
		while(!c[0]){
			int p=1,t=0;
			for(int j=1;j<=i;j++)
			{
				if(!c[j]) t+=p*4; else t+=p*7;
				p*=10;
			}
			a[++tot]=t;
			int j=i;
			while(c[j]) {c[j]=0,j--;}
			c[j]=1;
		}
	}
	sort(a+1,a+tot+1);
	a[0]=0;
	a[tot+1]=1000000000+1;
	scanf("%d%d%d%d%d",&pl,&pr,&vl,&vr,&k);
	for(int x=1;x<=tot;x++){
		int y=x+k-1;
		if(y>tot) break;
		int al,ar,bl,br;
		al=a[x-1]+1;
		ar=a[x];
		bl=a[y];
		br=a[y+1]-1;
		if(min(ar,pr)>=max(al,pl)&&min(br,vr)>=max(bl,vl)) ans=ans+(long long)(min(ar,pr)-max(al,pl)+1)*(min(br,vr)-max(bl,vl)+1);
		if(min(ar,vr)>=max(al,vl)&&min(br,pr)>=max(bl,pl)) ans=ans+(long long)(min(ar,vr)-max(al,vl)+1)*(min(br,pr)-max(bl,pl)+1);
	}
	for(int i=1;i<=tot;i++)
		if(pl<=a[i]&&a[i]<=pr&&vl<=a[i]&&a[i]<=vr&&k==1) ans--;
	//printf("%lld\n",ans);
//	ans=ans/(double)((pr-pl+1)*(vr-vl+1));
//	if(ans>(long long)(pr-pl+1)*(vr-vl+1)) printf("%.15f\n",ans/(double)(pr-pl+1)/(double)(vr-vl+1)/2.0); else 
	printf("%.15f\n",ans/(double)(pr-pl+1)/(double)(vr-vl+1));
	return 0;
}