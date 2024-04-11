#include <cstdio>

int main(){
	int type;
	char s[10];
	scanf("%d", &type);
	scanf("%s", s);
	int cnt = 0;
	if ('6' <= s[3])
		s[3] = '0';
	int num = (s[0] - '0') * 10 + s[1] - '0';
	if (type == 24){
		if (num >= 24)
			s[0] = '0';
	}
	else{
		if (num < 1 || 12 < num)
			s[0] = (s[1] == '0') + '0';
	}
	puts(s);
	return 0;
}