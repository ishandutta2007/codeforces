#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
char s[N];
int cnt[30], n;

void solve() {
	memset(cnt, 0, sizeof(cnt));
	scanf("%s", s + 1), n = strlen(s + 1);
	for(int i = 1; i <= n; i++) ++cnt[s[i] - 'a'];
	
	for(int i = 0; i < 26; i++) 
		if(cnt[i] == 1) {
			printf("%c", 'a' + i);
			for(int j = 0; j < 26; j++) {
				if(j == i) continue;
				while(cnt[j]) printf("%c", 'a' + j), --cnt[j];
			}
			printf("\n");
			return;
		}
	
	int fir = -1, sec = -1, thi;
	for(int i = 0; i < 26 && fir == -1; i++) if(cnt[i]) fir = sec, sec = i;
	
	if(fir == -1) return printf("%s\n", s + 1), void();
	
	if(cnt[fir] - (n - cnt[fir]) >= 3) {
		printf("%c%c", fir + 'a', sec + 'a');
		cnt[sec]--, cnt[fir]--;
		thi = sec + 1;
		while(!cnt[thi] && thi < 26) thi++;
		if(thi < 26) {
			while(cnt[fir]) printf("%c", fir + 'a'), --cnt[fir];
			printf("%c", thi + 'a'), --cnt[thi];
			while(cnt[sec]) printf("%c", sec + 'a'), --cnt[sec];
		}
		else {
			while(cnt[sec]) printf("%c", sec + 'a'), --cnt[sec];
			while(cnt[fir]) printf("%c", fir + 'a'), --cnt[fir];
		}
	}
	else {
		if(cnt[fir]) printf("%c", fir + 'a'), cnt[fir]--;
		if(cnt[fir]) printf("%c", fir + 'a'), cnt[fir]--;
		while(cnt[fir]) {
			printf("%c%c", sec + 'a', fir + 'a'), cnt[fir]--, cnt[sec]--;
			while(!cnt[sec] && sec < 26) ++sec;
		}
		while(cnt[sec]) printf("%c", sec + 'a'), cnt[sec]--;
	}
	
	for(int i = sec + 1; i < 26; i++)
		while(cnt[i]) printf("%c", 'a' + i), --cnt[i];
	
	printf("\n");	
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}