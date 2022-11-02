#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

char s[2000100];
int tot, tmp;

int main(){
	gets(s);
	int len = strlen(s);
	for(int i = len; i --; ){
		if(s[i] == 'a'){
			tot = (tot + tmp) % mod;
			tmp = 2 * tmp % mod;
		}
		else tmp ++;
	}
	cout << tot << endl;
}