#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi arr[150];



bool contain(vi a,vi b){

	int ret;

	for(int i=0;i<a.size();i++){

		ret=0;

		for(int j=0;j<b.size();j++)

		if(a[i]==b[j]) ret=1;

		if(!ret) return ret;

	}

	return ret;

}



int main(){

//	freopen("in.txt","r",stdin);

	

	int n,k,kk,p;

	cin>>n;

	for(int i=1;i<=n;i++) {

		scanf("%d",&k);

		for(int j=1;j<=k;j++) {

			scanf("%d",&kk);

			arr[i].push_back(kk);

		}

	}

	for(int i=1;i<=n;i++) {

		p=0;

		for(int j=1;j<=n;j++)	

		if(j!=i && contain(arr[j],arr[i])) { puts("NO");  p=1; break;}

		if(p) continue;

		puts("YES");

	}

	

	return 0;

}