#include <bits/stdc++.h>

using namespace std;

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ? -1 : 1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

char ans[30] , s[30];

int A , B , pos[120];

int main() {
	scanf("%s" , s);
	memset(pos , -1 , sizeof pos);
	for (int i = 0 ; i < 27 ; i ++) {
		if (pos[s[i]] != -1) {
			if (i - pos[s[i]] == 1) return puts("Impossible") , 0;	
			else {A = pos[s[i]] , B = i ;break;}
		}
		pos[s[i]] = i;
	}
	int m =  (B - A - 1) >> 1; 
	for (int i = 12 - m ; i <= 12 ; A ++ , i ++) 
		A == B ? A ++ : A , ans[i] = s[A % 27];
	for (int i = 25 ; i >= 13 ; A ++ , i --) 
		A == B ? A ++ : A , ans[i] = s[A % 27];
	for (int i = 0 ; i <= 12 - m - 1 ; A ++ , i ++) 
		A == B ? A ++ : A , ans[i] = s[A % 27];
	for (int i = 0 ; i < 26 ; i ++) printf("%c" , ans[i]) , i == 12 ? puts("") : i = i;
	return 0;
}