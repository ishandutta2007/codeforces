#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 1e6 + 7;

int leftq = 60;

bool have[N];

int int_rand(){
	int c = (1 << 15);
	int res = 0;

	for(int i = 0; i < 2; i++){
		res *= c;
		res += rand() % c;
	}

	return res;
}

int query1(int ind){
	cout << "? " << ind << "\n";
	cout.flush();

	int x;

	cin >> x;

	leftq--;
	return x; 
}

bool query2(int x){
	cout << "> " << x << "\n";
	cout.flush();

	bool b;

	cin >> b;

	leftq--;
	return b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	int l = 0, r = inf, mid;

	while(l != r){
		mid = (l + r) / 2;

		if(!query2(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}

	int mx = l;

	vector<int> v;

	leftq = min(leftq, n);

	int i = 1;

	while(leftq){
		int x = int_rand() % n + 1;

		if(have[x]){
			for(; i <= n; i++){
				if(!have[i]){
					break;
				}
			}
			x = i;
			i++;
		}

		have[x] = true;
		v.push_back(query1(x));
	}

	sort(v.begin(), v.end());

	int res;

	for(int i = 0; i < v.size() - 1; i++){
		if(i == 0){
			res = v[i+1] - v[i];
		}
		else{
			res = __gcd(res, v[i+1] - v[i]);
		}
	}
	
	cout << "! " << mx - (n-1)*res << " " << res << "\n";
	cout.flush();

	return 0;
}