#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 100010

char s[N], t[10];
int n, m, q;

int main(){

	///freopen("in.txt", "r", stdin);

	scanf("%d %s", &n, s + 1);
//	puts(s + 1);

	for(scanf("%d", &q); q --; ){
		scanf("%d %s", &m, t);
		char ch = t[0];

		int st = 1, en = 1, ans = 0, gas = 0;
	//	cout << ch << m<< endl;
		while(en <= n){
		//	cout << s[en] << gas << endl;
			if(s[en] == ch){
				en ++;
				ans = max(en - st, ans);
		//		cout <<"AA " << en << st << endl;
				continue;
			}
			if(gas < m){
				en ++;
				gas ++;
				ans = max(en - st, ans);
			//	cout << "BB  "<< en << st << endl;
				continue;
			}
			else{
				if(s[st] != ch) gas --;
				st ++;
			}
		}
		printf("%d\n", ans);
	}

}