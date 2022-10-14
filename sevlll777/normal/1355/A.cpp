#include<bits/stdc++.h>
using namespace std;

pair<int,int> getInfo(long long n) {
	int Max = 01, Min = 10;
	while (n) {
		int d = n%10;
		Max = max(Max,d);
		Min = min(Min,d);
		n /= 10;
	}
	return make_pair(Min,Max);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t --> 0) {
   		long long a, k;
   		cin >> a >> k;
   		int cnt = 0;
		long long n = 1;
   		for (int i=2; i<=k and cnt<405; i++) {
   		        cnt++;
   			pair<int,int> info = getInfo(a);
   			int Min = info.first, Max = info.second;
   			a += Min * Max;
   			if (Min == 0) break;
		}
		cout << a << "\n";
    }
}