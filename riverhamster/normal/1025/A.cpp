#include <cstdio>
#include <cstring>

char s[100005];
int cnt[30];

int main(){
	int n, len;
	scanf("%d", &n);
	scanf("%s", s);
	len = strlen(s);
	for(int i=0; i<len; i++) 
		cnt[s[i] - 'a']++;
	int cnt1 = 0, cnt2 = 0;
	for(int i=0; i<26; i++)
		if(cnt[i] == 1) cnt1++;
	else if(cnt[i] != 0) cnt2++;
	if(cnt1 > 0 && cnt2 == 0 && n != 1) puts("No");
	else puts("Yes");
	return 0;
}