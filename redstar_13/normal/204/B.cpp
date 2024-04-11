#include<bits/stdc++.h>



#define NN 100011

using namespace std;



map<int, int> cnt[2], vst;



int main(){

	int n,i,j,h,f,b;

	cin>>n;

	for(i=0; i<n; i++){

		scanf("%d%d", &f, &b);

		if(!vst[f]) vst[f]=1;

		if(!vst[b]) vst[b]=1;

		if(f!=b) cnt[0][f]++, cnt[1][b]++;

		else cnt[0][f]++;

	}

	

	int ans=NN;

	

	for(map<int, int>::iterator it=vst.begin(); it!=vst.end(); it++){

		int u=it->first;

		int tmp=cnt[0][u]-(n+1)/2;

		if(tmp>=0) ans=0;

		else if(tmp+cnt[1][u]>=0) ans=min(ans, -tmp);

	}

	

	if(ans==NN) puts("-1");

	else cout<<ans<<endl;

	return 0;

}