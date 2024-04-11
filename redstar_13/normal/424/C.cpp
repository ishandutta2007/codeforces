#include<bits/stdc++.h>

#define NN 1000100

using namespace std;

typedef long long INT;



INT p[NN],ans=0,nod[NN];

int main(){

//	freopen("in.txt","r",stdin);

	int n;

	cin>>n;

	nod[0]=0;

	for(int i=1;i<=n;i++) nod[i]=nod[i-1]^i;

	for(int i=1;i<=n;i++) {scanf("%I64d",&p[i]); ans^=p[i];}

	for(int i=1;i<=n;i++){

		int j=n%i;

		int k=n/i%2;

		if(j) ans^=nod[j];

		if(k) ans^=nod[i-1];

	}

	cout<<ans;

	return 0;

}