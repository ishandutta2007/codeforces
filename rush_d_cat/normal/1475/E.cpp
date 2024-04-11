#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000 + 10;
const int mod = 1e9 + 7;
int c[N][N];
int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);	
    
    for (int i = 0; i < N; i ++) c[i][0] = 1;
    for (int i = 1; i < N; i ++) for (int j = 1; j <= i; j ++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
   // printf("ok\n");
    int t; cin >> t;
	while (t --) {
    	int n, k; 
    	cin >> n >> k;
    	vector<int> a(n);
    	for (int i = 0; i < n; i ++) cin >> a[i];
    	sort(a.begin(), a.end(), greater<>());

    	int val = a[k-1];
    	int cnt1 = 0, cnt2 = 0;
    	int pos = k-1; while(pos>=0 && a[pos]==val) {cnt1++; pos--;}
    	for (int i = 0; i < n; i ++) if (a[i] == val) cnt2 ++;
    	cout << c[cnt2][cnt1] << endl;
	}
}