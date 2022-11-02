#include<bits/stdc++.h>
using namespace std;

char s[10020];
string arr[6];
int bit, tmp, n, k;

bool vowel(char ch){
	if(ch == 'a') return true;
	if(ch == 'e') return true;
	if(ch == 'i') return true;
	if(ch == 'o') return true;
	if(ch == 'u') return true;
	return false;
}

int main(){
///	freopen("a.in", "r", stdin);
	bit = 7;
	scanf("%d %d", &n, &k);
	//cout << n << k << endl;
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < 4; j ++){
			arr[j] = "";
			scanf("%s", s);
			int gas = 0, len = strlen(s);
			for(int t = strlen(s); t --; ){
				if(vowel(s[t])) gas ++;
				if(gas == k){
					arr[j] += s + t;
					//for(; t < len; t ++) arr[j] += s[t];
					break;
				}
			}
			if(arr[j] == ""){ puts("NO"); return 0; }
		}
	//	cout << bit << endl;
		tmp = 0;
	//	printf("%s\n", arr);
		if((arr[0] == arr[1]) && (arr[2] == arr[3])) tmp += 1;
		if((arr[0] == arr[2]) && (arr[1] == arr[3])) tmp += 2;
		if((arr[0] == arr[3]) && (arr[1] == arr[2])) tmp += 4;
	//	cout << tmp << endl;
		bit &= tmp;
	}
//	cout << bit << endl;
	if(bit == 7) puts("aaaa");
	else if(bit == 1) puts("aabb");
	else if(bit == 2) puts("abab");
	else if(bit == 4) puts("abba");
	else puts("NO");
}