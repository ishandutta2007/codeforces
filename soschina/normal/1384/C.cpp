#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int N = 1e5 + 2;

int t, n, ans;
bool flag;
char a[N], b[N];
vector<int> h[19];

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0, flag = true;
		scanf("%d%s%s", &n, a + 1, b + 1);
		for(int i = 1; i <= n; i++){
			a[i] -= 'a', b[i] -= 'a';
			if(a[i] < b[i]) h[a[i]].push_back(i);
			else if(a[i] > b[i]) flag = false;
		}
		for(int i = 0; i < 19; i++) if(h[i].size()){
			ans++;
			int tar = 20;
			for(auto j : h[i]) tar = min(tar, (int) b[j]);
			for(auto j : h[i]) if(tar != b[j]) h[tar].push_back(j);
			h[i].clear();
		}
		printf("%d\n", flag ? ans : -1);
	}
	return 0;
}