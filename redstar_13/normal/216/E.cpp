#include<bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;



INT tmp[NN], a[NN];

map<INT, int> cnt;



int main(){

	

	int k,b,n,i,j;

	cin>>k>>b>>n;

	for(i=0; i<n; i++){

		scanf("%d" ,a+i);

	}

	INT ans=0;

	if(b==0){

		if(a[0]==0) ans=tmp[0]=1;

		for(i=1; i<n; i++){

			if(a[i]==0) tmp[i]=tmp[i-1]+1;

			else tmp[i]=0;

			ans+=tmp[i];

		}

		cout<<ans<<endl;

		return 0;

	}

	

	INT st=0;

	int mod=k-1;

	if(b==k-1) b=0;

	cnt[0]=1;

//	cout<<b<<endl;

	for(i=0; i<n; i++){

		st=(st+a[i])%mod;

		if(st<0) st+=mod;

		ans+=cnt[(st-b+mod)%mod];

		cnt[st]++;

//		cout<<(st-b+mod)%mod<<' '<<st<<' '<<cnt[st]<<' '<<ans<<endl;

	}

	if(b==0){

		if(a[0]==0) tmp[0]=1, ans--;

		for(i=1; i<n; i++){

			if(a[i]==0) tmp[i]=tmp[i-1]+1;

			else tmp[i]=0;

			ans-=tmp[i];

		}

	}

	cout<<ans<<endl;

	return 0;

}