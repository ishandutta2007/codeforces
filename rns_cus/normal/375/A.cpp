#include<bits/stdc++.h>
using namespace std;

#define N 2000100

int a[10], fg[10], cnt;
char s[N], t[N];

int main(){
	///freopen("a.in", "r", stdin);
	a[1] = 1;
	a[2] = 6;
	a[3] = 8;
	a[4] = 9;

	scanf("%s", s);
	int len = strlen(s), tmp = 0, tot = 1;

	for(int i = 0; i < len; i ++){
		if(s[i] == '1' && fg[1] == 0){ fg[1] = 1; }
		else if(s[i] == '6' && fg[6] == 0) { fg[6] = 1; }
		else if(s[i] == '8' && fg[8] == 0) { fg[8] = 1; }
		else if(s[i] == '9' && fg[9] == 0) { fg[9] = 1; }
		else{
			tmp = (tmp * 10 + s[i] - '0') % 7;
			tot = tot * 10 % 7;
			t[cnt ++] = s[i];
		}
	}

	assert(cnt == len - 4);

	while(true){
		int ttt = 0;
		for(int i = 1; i <= 4; i ++) ttt = (ttt * 10 + a[i]) % 7;
		if( (ttt * tot + tmp) % 7 == 0 ){
			for(int i = 1; i <= 4; i ++) printf("%d", a[i]); puts(t);
			return 0;
		}
		if(!next_permutation(a + 1, a + 5)) break;
	}
}