#include<bits/stdc++.h>
using namespace std;

const int inf=(1<<30);
int n,k;
int p[300005],c[300005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char s[10];
		scanf("%d%s",&p[i],s);
		if(s[0]=='R')c[i]=0;else if(s[0]=='B')c[i]=1;else c[i]=2;
		if(c[i]==2)k++;
	}
	if(!k){
		int ans=0;
		int a=(1<<30),b=0;
		for(int i=0;i<n;i++)if(c[i]==0)a=min(a,p[i]),b=max(b,p[i]);
		if(b>=a)ans+=b-a;
		a=(1<<30),b=0;
		for(int i=0;i<n;i++)if(c[i]==1)a=min(a,p[i]),b=max(b,p[i]);
		if(b>=a)ans+=b-a;
		printf("%d\n",ans);
	}else{
		int now=-1;
		long long ans=0;
		for(int i=-1,j=0;i<n;i=j+1){
			for(j=i;j<n&&c[j]!=2;j++);
			if(i==-1){
				int a=inf,b=inf;
				for(int k=0;k<j;k++)if(c[k]==0)a=min(a,p[k]);else if(c[k]==1)b=min(b,p[k]);
				if(a<p[j])ans+=p[j]-a;
				if(b<p[j])ans+=p[j]-b;
			}else if(j==n){
				int a=0,b=0;
				for(int k=i;k<n;k++)if(c[k]==0)a=max(a,p[k]);else if(c[k]==1)b=max(b,p[k]);
				if(a>p[i-1])ans+=a-p[i-1];
				if(b>p[i-1])ans+=b-p[i-1];
			}else{
				long long tmp=1ll<<50;
				int la=p[i-1],lb=p[i-1],ma=0,mb=0;
				for(int k=i;k<j;k++)
					if(c[k]==0){
						ma=max(ma,p[k]-la);
						la=p[k];
					}else if(c[k]==1){
						mb=max(mb,p[k]-lb);
						lb=p[k];
					}
				ma=max(ma,p[j]-la);
				mb=max(mb,p[j]-lb);
				tmp=min(tmp,3ll*(p[j]-p[i-1])-ma-mb);
				tmp=min(tmp,2ll*(p[j]-p[i-1]));
				ans+=tmp;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}