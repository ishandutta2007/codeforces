#include<bits/stdc++.h>
using namespace std;

int n,s1,s2,a[100005],b[100005],c[100005];
bool check(int x){
	for(int i=0;i<n;i++)c[i]=n+1;
	int t=0;
	for(int i=n-1;i>=0;i--){
		if(t){
			int f=0,e=t-1;
			while(f<e){
				int mid=f+e+1>>1;
				if(a[b[mid]]<=a[i]+x)e=mid-1;else f=mid;
			}
			if(a[b[f]]>a[i]+x)c[i]=min(c[i],b[f]);
		}
		while(t&&a[b[t-1]]<=a[i])t--;
		b[t++]=i;
	}
	t=0;
	for(int i=n-1;i>=0;i--){
		if(t){
			int f=0,e=t-1;
			while(f<e){
				int mid=f+e+1>>1;
				if(a[b[mid]]>=a[i]-x)e=mid-1;else f=mid;
			}
			if(a[b[f]]<a[i]-x)c[i]=min(c[i],b[f]);
		}
		while(t&&a[b[t-1]]>=a[i])t--;
		b[t++]=i;
//		for(int j=0;j<t;j++)printf("%d ",b[j]);printf("\n");
	}
//	printf("%d\n",x);
//	for(int i=0;i<n;i++)printf("%d ",a[i]);printf("\n");
//	for(int i=0;i<n;i++)printf("%d ",c[i]);printf("\n");
	for(int i=1;i<n;i++){
		c[i]=max(c[i],c[i-1]);
	}
	for(int i=0;i<n;i++)if(c[i]<=i+1)return 0;
	return 1;
}
bool Check(int x){
	a[0]=s1;if(check(x))return 1;
	a[0]=s2;if(check(x))return 1;
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&s1,&s2);
	for(int i=1;i<n+1;i++)scanf("%d",&a[i]);n++;
	int h=abs(s1-s2),t=1000000000;
	while(h<t){
		int x=h+t>>1;
		if(Check(x))t=x;else h=x+1;
	}
	printf("%d\n",h);
	return 0;
}