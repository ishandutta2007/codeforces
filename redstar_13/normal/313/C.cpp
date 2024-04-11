#include<bits/stdc++.h>

#define NN 4000010



using namespace std;

typedef long long INT;

INT sum[NN],a[NN];



int main(){

//	freopen("in.txt","r",stdin);

	int n;

	INT num[30],p=1,len=0;

	cin>>n; 

	for(int i=0;i<n;i++) scanf("%d",&a[i]);

	while(p<=n)	{ num[len++]=p;	p*=4; }

	sort(a,a+n);

	

	INT ans=0;

	sum[0]=0;

	int pp=0,k=1;

	for(int i=n-1;i>=0;i--) sum[k]=sum[k-1]+a[i],k++;

	

	for(int i=0;i<len;i++) ans+=sum[num[i]];

	

	cout<<ans<<endl;

	return 0;

}