#include<bits/stdc++.h>



using namespace std;



#define MM 210000

typedef long long INT;



int n,k,x;

INT a[MM],ans,mx,sum[100],r;



int main()

{

//	freopen("in.txt","r",stdin);

	

	scanf("%d%d%d",&n,&k,&x);

	for(int i=0; i<n; i++){

		 scanf("%I64d", a+i);

		 for(int j=0; j<64; j++) sum[j]+=((a[i]>>j)&1LL);

	}

	for(int i=0; i<n; i++){

		r=a[i];

		for(int j=0; j<64; j++) sum[j]-=((r>>j)&1LL);

		for(int j=0; j<k; j++) r*=x;

		for(int j=0; j<64; j++) sum[j]+=((r>>j)&1LL);

		ans=0;

		for(int j=0; j<64; j++) ans+=(1LL<<j)*(sum[j]>0);

		mx=max(ans,mx);

		for(int j=0; j<64; j++) sum[j]-=((r>>j)&1LL);

		for(int j=0; j<64; j++) sum[j]+=((a[i]>>j)&1LL);

	}

	cout<<mx<<endl;

}