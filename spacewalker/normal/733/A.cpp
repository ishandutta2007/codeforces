#include <bits/stdc++.h>

using namespace std;

char jumper[110];
string vowels = "AEIOUY";

int main() {
	scanf("%s", jumper);
	int n = strlen(jumper);
	jumper[n] = 'A';
	int ans = 0, lastVowel = -1;
	for (int i = 0; jumper[i]; ++i) {
	    bool isVowel = false;
	    for (char c : vowels) if (c == jumper[i]) isVowel = true;
	    if (isVowel) {
	        ans = max(ans, i - lastVowel);
	        lastVowel = i;
	    }
	}
	printf("%d\n", ans);
}