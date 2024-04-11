#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;

int pr[500050], nx[500050];
int tog[500050];
int st, ed, n, m, p, d;
string s, order;
map<int, int> M;

void init_link(){
	st = 0;
	for(int i = 0; i < n; i++){
		pr[i] = (i == 0 ? -1 : i-1);
		nx[i] = (i == n - 1 ? -1: i+1);
	}
}

int link_delete(int i){
	int l,r;
	if(s[i] == '(') l = i, r = tog[i];
	else l = tog[i], r = i;
	
	if(st == l){
		return st = nx[r];
	}
	else{
		int next = nx[r], prev = pr[l];
		nx[prev] = next;
		if(next != -1) pr[next] = prev;
		else return prev;
		return next;
	}
	
}

int main(){
	scanf("%d%d%d", &n, &m, &p);
	getchar();
	getline(cin, s);
	getline(cin, order);
	
	d = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '(') M[++d] = i;
		else{
			int pos = M[d];
			tog[i] = pos; tog[pos] = i;
			d--;
		}
	}
	st = 0;
	int cur = p - 1;
	
	init_link();
	
	for(int i = 0; i < m; i++){
		char c = order[i];
		if(c == 'L') cur = pr[cur];
		if(c == 'R') cur = nx[cur];
		if(c == 'D'){
			cur = link_delete(cur);
		}
	}
	
	int pos = st;
	while(pos != -1){
		printf("%c", s[pos]);
		pos = nx[pos];
	}
	
}