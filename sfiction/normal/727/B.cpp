#include <cctype>
#include <cstdio>
#include <algorithm>

const int MAXL = 1E3 + 10;

char s[MAXL];

int main(){
	scanf("%s", s);
	char *p = s;
	long long sum = 0;
	while (*p){
		int t = 0, last = -MAXL;
		for (; isalpha(*p); ++p);
		for (; *p && !isalpha(*p); ++p, ++last){
			if (*p == '.')
				last = 0;
			else
				t = t * 10 + *p - '0';
		}
		if (last != 3)
			t *= 100;
		sum += t;
	}
	int m = 0, loc = 3;
	if (sum % 100){
		s[0] = '0' + sum % 10;
		s[1] = '0' + sum / 10 % 10;
		s[2] = '.';
		m = 3, loc = 2;
		if (sum < 100)
			s[m++] = '0';
	}
	
	for (sum /= 100; sum; sum /= 10){
		if (m % 4 == loc)
			s[m++] = '.';
		s[m++] = '0' + sum % 10;
	}
	std::reverse(s, s + m);
	s[m] = '\0';
	puts(s);
	return 0;
}