#include <bits/stdc++.h>

using namespace std;

const long long N = 5207;

string s;
bitset<N> b[N];

vector<long long> d;

long long n;

bool check(long long x){
	for(int i = 0; i < n; i += x){
		for(int j = 0; j < n; j += x){
			for(int k = i; k < i + x; k++){
				for(int k2 = j; k2 < j + x; k2++){
					if(b[k][k2] != b[i][j]){
						return false;
					}
				}
			}
		}
	}

	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long nd;

	cin >> n;

	nd = n / 4;

	for(int i = 0; i < n; i++){
		cin >> s;

		for(int j = 0; j < nd; j++){
			int x;

			if(s[j] >= '0' && s[j] <= '9'){
				x = s[j] - '0';
			}else{
				x = s[j] - 'A' + 10;
			}

			int qj = 4*j;

			b[i][qj] = x & (1 << 3);
			b[i][qj + 1] = x & (1 << 2);
			b[i][qj + 2] = x & (1 << 1);
			b[i][qj + 3] = x & (1 << 0);
 		}
	}

	long long i = 1, n2 = n;

	for(i = 2; i*i <= n2; i++){
		while(n2 % i == 0){
			d.push_back(i);
			n2 /= i;
		}
	}

	if(n2 != 1){
		d.push_back(n2);
		n2 = 1;
	}

	long long mx = 1;

	for(long long i = 0; i < d.size(); i++){
		if(check(mx * d[i])){
			mx *= d[i];
		}
	}

	cout << mx << "\n";

	return 0;
}
/*
4
3
3
C
C
*/