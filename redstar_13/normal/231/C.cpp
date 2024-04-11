#include<bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef double DO;



int a[NN];

INT sum[NN];

map<int, int> cnt, vst;



INT calc(int u, int n){

	INT ans=(INT)a[n]*(n-u)-(sum[n-1]-sum[u-1]);

	return ans;

}



int main(){

	int n,k,i,j;

	cin>>n>>k;

	for(i=1; i<=n; i++){

		scanf("%d", a+i);

		cnt[a[i]]++;

	}

	

	sort(a+1, a+n+1);

	

	for(i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];

	

	INT ans, mn=0;

	for(i=1; i<=n; i++){

//		cout<<a[i]<<' '<<sum[i]<<endl;

		if(vst[a[i]]) continue;

		vst[a[i]]=1;

		int st=1, ed=i, mid;

		while(ed>st+1){

			mid=(st+ed)/2;

			if(calc(mid, i)>k) st=mid;

			else ed=mid;

		}

		if(calc(st, i)<=k) ed=st;

		if(i-ed+cnt[a[i]]>mn) {

//			cout<<a[i]<<' '<<ed<<' '<<calc(ed, i)<<' '<<cnt[a[i]]<<endl;

			ans=a[i];

			mn=i-ed+cnt[a[i]];

		}

	}

	cout<<mn<<' '<<ans<<endl;

	return 0;

}