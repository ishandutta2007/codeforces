#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

typedef long long ll;

int n;
int stre[500050];
ll pre[500050];
ll suf[500050];
string s;
ll sum = 0;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &stre[i]);
	getchar();
	getline(cin, s);
	pre[0] = s[0] == 'A' ? stre[0] : -stre[0];
	for(int i = 1; i < n; i++){
		pre[i] = pre[i-1] + (s[i] == 'A' ? stre[i] : -stre[i]);
	}
	suf[n-1] = s[n-1] == 'A' ? stre[n-1] : -stre[n-1];
	for(int i = n-1; i >= 0; i--){
		suf[i] = suf[i+1] + (s[i] == 'A' ? stre[i] : -stre[i]);
	}
	ll res = 0;
	for(int i = 0; i < n; i++){
		res = max(pre[i], res);
		res = max(res, suf[i]);
		sum += s[i] == 'B' ? stre[i] : 0;
	}
	cout << sum + res;
	
}