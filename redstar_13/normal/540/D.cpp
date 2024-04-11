#include <bits/stdc++.h>



#define NN 111

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;

typedef double DO;



DO dp[NN][NN][NN][4];



int main() {

	int r, s, p, i, j,k;

	cin>>r>>s>>p;

	

	for(i=1; i<=100; i++){

		

		dp[0][0][i][2]=1;

		dp[0][i][0][1]=1;

		dp[i][0][0][0]=1;

		

		for(j=1; j<=100; j++){

			dp[0][i][j][1]=1;

			dp[i][0][j][2]=1;

			dp[i][j][0][0]=1;

		}

	}

	

	for(i=1; i<=r; i++){

		for(j=1; j<=s; j++){

			for(k=1; k<=p; k++){

				DO re=2*i*j+2*i*k+2*j*k;

				

				dp[i][j][k][0]=2*(i*j*dp[i][j-1][k][0]+i*k*dp[i-1][j][k][0]+j*k*dp[i][j][k-1][0])/re;

				

				dp[i][j][k][1]=2*(i*j*dp[i][j-1][k][1]+i*k*dp[i-1][j][k][1]+j*k*dp[i][j][k-1][1])/re;

				

				dp[i][j][k][2]=2*(i*j*dp[i][j-1][k][2]+i*k*dp[i-1][j][k][2]+j*k*dp[i][j][k-1][2])/re;

					

			}

		}

	}

	

	printf("%.10lf %.10lf %.10lf\n", dp[r][s][p][0], dp[r][s][p][1], dp[r][s][p][2]);

	





	return 0;

}