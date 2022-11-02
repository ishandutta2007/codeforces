#include<bits/stdc++.h>
using namespace std;

#define N 1000100

int root[N], arr[N], ans, brr[N], n;

int find_root(int x){
	return root[x] == x ? x : root[x] = find_root(root[x]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d", arr + i);
		root[i] = i;
	}
	int idx = 0, idx1;
	for(int i = 1; i <= n; i ++){
		if( i == arr[i] ) idx = i;
		int x = find_root(i);
		int y = find_root(arr[i]);
		if(x != y){ brr[i] = arr[i]; root[x] = y; }
		else{
			idx1 = i;
			ans ++;
			brr[i] = 0;
		}
	}
	if(idx){
		cout << ans - 1 << endl;
		for(int i = 1; i <= n; i ++){
			if(brr[i]) printf("%d ", brr[i]);
			else printf("%d ", idx);
		}
	}
	else{
		cout << ans << endl;
		for(int i = 1; i <= n; i ++){
			if(brr[i]) printf("%d ", brr[i]);
			else printf("%d ", idx1);
		}
	}
}