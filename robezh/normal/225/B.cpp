#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

const int LAR = 1000000000;

int s,k;
vector<int> fib;
vector<int> res;

int get_next_fib(){
	int n = fib.size() - 1;
	int res = 2 * fib[n] - (n - k >= 0 ? fib[n-k] : 0);
	
	return res;
}


int main(){
	fib.push_back(1), fib.push_back(1);
	scanf("%d%d", &s, &k);
	while(true){
		int next_fib = get_next_fib();
		fib.push_back(next_fib);
		if(next_fib > LAR) break;
	}
	res.push_back(0);
	int t = fib.size() - 1;
	while(t >= 0){
		if(s >= fib[t]){
			s -= fib[t];
			res.push_back(fib[t]);
		}
		t--;
	}
	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++){
		printf("%d ", res[i]);
	}
	
}