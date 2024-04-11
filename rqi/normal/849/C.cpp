#include <bits/stdc++.h>
using namespace std;
char l[26];

int times[26];
int main() {
	l[0] = 'a';
	l[1] = 'b';
	l[2] = 'c';
	l[3] = 'd';
	l[4] = 'e';
	l[5] = 'f';
	l[6] = 'g';
	l[7] = 'h';
	l[8] = 'i';
	l[9] = 'j';
	l[10] = 'k';
	l[11] = 'l';
	l[12] = 'm';
	l[13] = 'n';
	l[14] = 'o';
	l[15] = 'p';
	l[16] = 'q';
	l[17] = 'r';
	l[18] = 's';
	l[19] = 't';
	l[20] = 'u';
	l[21] = 'v';
	l[22] = 'w';
	l[23] = 'x';
	l[24] = 'y';
	l[25] = 'z';
	int k;
	cin >> k;
	int letter = 0;
	int sum;
	int x= 0;
	int j = 0;
	if(k == 0){
		cout << "a";
	}
	while(k > 0){
		while(sum <= k){
			sum = (x * (x+1))/2;
			x++;
		}
		k-=((x-2) * (x-1))/2;
		times[j] = x-1;
		x = 0;
		j++;
		sum = 0;
	}
	for(int i = 0; i < 26; i++){
		for(int m = 0; m < times[i]; m++){
			cout << l[i];
		}
	}
	
}