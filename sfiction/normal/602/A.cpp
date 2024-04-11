#include <cstdio>

typedef long long ll;

ll getNum(){
	int n, b;
	scanf("%d%d", &n, &b);
	ll ret = 0;
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		ret = ret * b + t;
	}
	return ret;
}

int main(){
	ll a = getNum(), b = getNum();
	printf("%c", a == b ? '=' : a < b ? '<' : '>');
	return 0;
}