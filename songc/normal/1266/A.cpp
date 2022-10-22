#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
char str[110];

int main(){
	scanf("%d", &N);
	while (N--){
		scanf("%s", str+1);
		int sum=0;
		bool tf=0, even=0;
		for (int i=1; str[i]; i++){
			int c = str[i] - '0';
			sum += c;
			if (c == 0){
				if (!tf) tf = true;
				else even = true;
			}
			else if (c%2==0) even = true;
		}
		if (tf && even && sum%3==0) printf("red\n");
		else puts("cyan");
	}
	return 0;
}