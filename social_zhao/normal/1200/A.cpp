#include<bits/stdc++.h>
using namespace std;

int get()
{
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

bool vis[15];
int n;
char act[150005];

void push_left()
{
	int pos = 0;
	while(vis[pos] == 1 && pos <= 9) {
		pos++;
	}
	vis[pos] = 1;
}

void push_right()
{
	int pos = 9;
	while(vis[pos] == 1 && pos >= 0) {
		pos--;
	}
	vis[pos] = 1;
}

void del(int i)
{
	vis[i] = 0;
}

int main()
{
	n = get();
	scanf("%s", act);
	int len = strlen(act);
	for(int i = 0; i < len; i++) {
		if(act[i] == 'L') push_left();
		else if(act[i] == 'R') push_right();
		else if(isdigit(act[i])) del(act[i] - '0');
	}
	for(int i = 0; i <= 9; i++) printf("%d", vis[i]);
	return 0;
}