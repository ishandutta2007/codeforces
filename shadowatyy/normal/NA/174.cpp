#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int c, h1, w1, h2, w2;

int main(){
	cin >> c >> h1 >> h2 >> w1 >> w2;
	if(w1 > w2){
		swap(h1, h2);
		swap(w1, w2);
	}
	
	LL res = 0;
	if(c / w1 < 10000000){
		for(int i = 0; i * w1 <= c; ++i)
			res = max(res, 1LL * i * h1 + 1LL * ((c - i * w1) / w2) * h2);

		printf("%lld\n", res);
		return 0;
	}
	
	if(1LL * h1 * w2 < 1LL * h2 * w1){
		swap(h1, h2);
		swap(w1, w2);
	}
	
	int nr = c / w1;
	int mn = max(0, nr - 10000000);
	
	for(int i = mn; i <= nr; ++i)
		res = max(res, 1LL * i * h1 + 1LL * ((c - i * w1) / w2) * h2);
	
	nr = c / w2;
	mn = max(0, nr - 10000000);
	
	for(int i = mn; i <= nr; ++i)
		res = max(res, 1LL * i * h2 + 1LL * ((c - i * w2) / w1) * h1);
	printf("%lld\n", res);
	return 0;
}