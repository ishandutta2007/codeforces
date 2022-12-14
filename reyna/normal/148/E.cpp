#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> arr[101];
int DP[110][110];
long long KS[10101];
int main(){
	int n,m;
	cin >> n >> m;
	for(int j = 0; j < n;j++){
		int k;
		cin >> k;
		for(int i = 0; i < k;i++){
			int a;
			cin >> a;
			arr[j].push_back(a);
		}
		int counter = 0;
		DP[j][0] = 0;
		for(int i = 0; i < arr[j].size();i++){
			counter+=arr[j][i];
		}
		int M = counter;
		counter = 0;
		for(int i = 0; i <= k;i++){
			for(int l = 0; l < i;l++){
				counter += arr[j][l];
			}
			DP[j][arr[j].size()-i] = max(DP[j][arr[j].size()-i],M-counter);
			for(int l = i; l < k;l++){
				counter += arr[j][l];
				counter -= arr[j][l-i];
				DP[j][arr[j].size()-i] = max(DP[j][arr[j].size()-i],M-counter);
			}
			counter = 0;
		}
	}
//	for(int i = 0; i < n;i++){
//		for(int j = 0; j <= arr[i].size();j++){
//			cout << DP[i][j] << " ";
//		}
//		cout << endl;
//	}
	for(int i = 1; i < m;i++){
		KS[i] = -1;
	}
	for(int i = 0; i < n;i++){
		for(int j = m; j >= 0;j--){
			for(int k = 0; k <= arr[i].size();k++){
				if(k > j){
					break;
				}
				if(KS[j-k] != -1){
					KS[j] = max(KS[j-k]+DP[i][k],KS[j]);
				}
			}
		//	cout << KS[j] << " j " << j << " i " << i << endl;
		}
	}
	cout << KS[m] << endl;
	return 0;
}