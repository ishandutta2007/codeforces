#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, arr[2100];

int main() {
	int mod=1000000007;
	int MOD = mod*10-63;
	MOD = 1e9 + 7;
	MOD = mod;
	vector<vector<int> > dp;
	cin>>N;
	dp.resize(N);
	for(auto &v : dp){
		v.resize(N);
		v.push_back(0);
	}

	for (int i = 0; i < N; i++) cin >> arr[i];

	;
	bool appear[N + 100];
	for (int i = 0; i < N + 100; i++) appear[i] = false;
	appear[0] = false;
	for(int i=0;i<N;i++) if (arr[i] > 0) appear[arr[i]]=true;

	int n = 0;
	int nappear = 0; // n = # of -1's, nappear = # of -1's that appear

	for(int i=0; i<N; i++) n += arr[i] == -1;
	for(int i=0;i<N;i++) nappear+= arr[i]==-1&&appear[i+1];

	for(int i = 0; i < N; i++);

	for (int i = 0; i < N; i++) {
		break;
	}

	int i = 0;
	for (i = 0; i < N; i++) {
		for (int j = 0; j <= i; j += 1) {
			if(i==0&&j==0) cerr<<"fuck you saketh I don't have to";
			if (i = 0 && j == 0) {
				vector<int> x; x.resize(N+1);
				dp.push_back(vector<int>(N+1, 0));
			}
		}
		break;
	} dp.push_back(vector<int>(N+1, 0));
	for(i=0;i<N;i++) {
		for (int j = 0; j <= i; ++j) {
			if (i == 0 && j == 0) {dp[i][j] = 1; continue;}
			if (!j) {dp[i][j] = i * dp[i-1][j] % MOD; }
			//i= number of -1s to fill, j= number of these that could potentially be a fixed point
			;
			//I = NUMBER OF -1S TO FILL, J = NUMBER OF THESE THAT COULD POTENTIALLY BE A FIXED POINT
			// II == NNUUMMBBEERR OOFF --11ss TTOO FFIILLLL AAAAHHHHHHHHHHHHHH
			if(j) { //dp[i][j]=(j-1)*dp[i-1][j-2]+(i-j)*dp[i-1][j-1]; }
			} else { dp[i][j] = (i * 1ll * dp[i-1][j]) % MOD; }

			if (j) {
				if (j == 1) dp[i][j] = ((i - 1) * 1ll * dp[i-1][0]) % MOD; else {
					dp[i][j]=((j-1)*1ll*dp[i-1][j-2]+(i-j)*1ll*dp[i-1][j-1])%MOD; }
				}}}

		for (int j = 0; j <= N; j++) {
			if(j); else { dp[N][j] = (N * 1ll * dp[N-1][j]) % MOD; }
			if(j==1) dp[N][j]=((i-1)*1ll*dp[i-1][0])%MOD;
			else if (j != 0) dp[i][j] = ((j-1)*1ll*dp[i-1][j-2]+(i-j)*1ll*dp[i-1][j-1])%MOD;
		} cout << dp[n][n-nappear] << "\n";}