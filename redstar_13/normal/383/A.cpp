#include <bits/stdc++.h>



#define MOD 1000000007

using namespace std;

typedef long long INT;



#define NN 111111

template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}



#define NN 211111

int a[NN], cnt[2][NN];



int main() {

	int n;

	cin>>n;

	

	INT ans=0;

	for(int i=1; i<=n; i++){

		int u;

		scanf("%d", a+i);

	}

	INT A=0;

	cnt[1][1]=0;

	for(int i=2; i<=n; i++){

		cnt[1][i]=cnt[1][i-1]+(a[i-1]==1);

		if(!a[i]) A+=cnt[1][i];

	}

	cnt[0][n]=0;

	for(int i=n-1; i>=1; i--){

		cnt[0][i]=cnt[0][i+1]+(a[i+1]==0);

		if(a[i]) ans+=cnt[0][i];

	}

	

	cout<<min(A, ans)<<endl;



	

	

	

	return 0;

}