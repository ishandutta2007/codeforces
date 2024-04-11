#include<bits/stdc++.h>
const int N=1003;
using namespace std;
int n,x[N],y[N],s;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d%d",x+i,y+i);
	for(;;){
		s=0;
		for(int i=0;i<n;i++)
		if(x[i]+y[i]&1)s++;
		if(s&&s<n){
			printf("%d\n",s);
			for(int i=0;i<n;i++)
			if(x[i]+y[i]&1)printf("%d ",i+1);
			return 0;
		}
		for(int i=0;i<n;i++)
		s=y[i],(y[i]+=x[i])>>=1,(x[i]-=s)>>=1;
	}
}