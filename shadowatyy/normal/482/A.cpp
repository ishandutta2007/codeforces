#include <bits/stdc++.h>

using namespace std;

int n, k;

int main(){
	scanf("%d %d", &n, &k);
	vector <int> res; int cnt = 0;
	for(int i = 1; i <= k; ++i){
		if(i%2 == 1)
			res.push_back(++cnt);
		else
			res.push_back(n - cnt + 1);
	}

	if(k%2 == 0){
		cnt = n - cnt;
		int Left = n - k;
		while(Left--)
			res.push_back(cnt--);
	}
	else{
		int Left = n - k;
		while(Left--)
			res.push_back(++cnt);
	}

	for(int v: res)
		printf("%d ", v);
	return 0;
}