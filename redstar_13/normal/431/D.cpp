#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



INT fact[30],c[77][77];

INT m, k;



void pre(){

	c[0][0]=1;

	for(int i=1; i<=64; i++){

		c[i][0]=1;

		for(int j=1; j<=i; j++){

			c[i][j]=c[i-1][j]+c[i-1][j-1];

		}

	}

}



INT calc(INT u){

	INT ans=0;

	int num=k;

	if(__builtin_popcountll(u)==k) ans++;

	

	for(int i=63; i>=0; i--){

		if(u&(1LL<<i) && num>=0)  ans+=c[i][num], num--;

	}

	

	return ans;

}



int main() {

	

	int i,j;

	cin>>m>>k;

	

	INT st=0, ed=1000000000000000001LL;

	

//	for(i=1; i<10; i++) cout<<i<<' '<<calc(i)<<endl;

	pre();

	

	while(ed>st+1){

		INT mid=(st+ed)/2;

		INT tmp=calc(mid*2)-calc(mid);

		if(tmp>m) ed=mid;

		else if(tmp<m) st=mid;

		else return cout<<mid<<endl, 0;

	}

	

	return 0;

}