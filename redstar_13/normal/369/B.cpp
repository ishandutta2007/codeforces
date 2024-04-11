#include<bits/stdc++.h>



using namespace std;



int main(){

//	freopen("in.txt","r",stdin);

	int a[1100];

	int n,k,l,r,ss,sk;

	cin>>n>>k>>l>>r>>ss>>sk;

	int re=sk%k;

	for(int i=1;i<=k;i++) a[i]=sk/k;

	for(int i=1;i<=re;i++) a[i]+=1;

	

	if(k==n){

		for(int i=1;i<=n;i++) printf("%d ",a[i]);

		return 0;

	}

	

	int skk,kk;

	skk=ss-sk; kk=n-k; re=skk%kk;

	for(int i=k+1;i<=n;i++) a[i]=skk/kk;

	for(int i=k+1;i<=k+re;i++) a[i]+=1;

	

	for(int i=1;i<=n;i++) printf("%d ",a[i]);

	return 0;

}