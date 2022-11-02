#include <bits/stdc++.h>



#define NN 5555

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int a[NN], up[NN][NN], bak[NN][NN];



int main() {

	int n,i,j;

	cin>>n;

	for(i=1; i<=n; i++) scanf("%d", a+i); 

	

	for(i=1; i<=n; i++){

		for(j=i; j<=n; j++){

			bak[i][j]=bak[i][j-1]+(a[i]>a[j]);

		}

	}

	

	for(j=1; j<=n; j++){

		for(i=j; i>=1; i--){

			up[i][j]=up[i+1][j]+(a[j]>a[i]);

		}

	}

	

	int tot=0;

	for(i=1; i<=n; i++){

		tot+=i-1-up[1][i];

	}

	

	int ans=1000000000;

	for(i=1; i<=n; i++){

		for(j=i+1; j<=n; j++){

			ans=min(ans, tot-bak[i][j]-bak[i][j-1]+up[i][j]+up[i][j]);

		}

		

	}

	int cnt=0;

	for(i=1; i<=n; i++){

		for(j=i+1; j<=n; j++){

			if(	ans==tot-bak[i][j]-bak[i][j-1]+up[i][j]+up[i][j]) cnt++;

		}

	}

	cout<<ans<<' '<<cnt<<endl;





	return 0;

}