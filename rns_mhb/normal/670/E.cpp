#include<bits/stdc++.h>
using namespace std;

#define N 501000

int pos[N], n, m, p, f[N];
char str[N], query[N];
stack<int> tmp;

void r(){
	p ++;
	if(f[p]) p = pos[p] + 1;
	if(p > n) p = n;
}

void l(){
	p --;
	if(f[p]) p = pos[p] - 1;
	if(p < 1) p = 1;
}

void del(){
	p = min(p,pos[p]);
	f[p] = f[pos[p]] = 1;
	int pp = pos[p];
	if(f[p-1]){
		pos[pos[p-1]] = pos[p];
		pos[pos[p]] = pos[p-1];
		p = pos[p-1];
	}
	if(f[pp+1]){
		pos[p] = pos[pp+1];
		pos[pos[pp+1]] = p;
	}
	if(pos[p] + 1 > n) p --;
	else p = pos[p] + 1;
}
main(){
	scanf("%d%d%d\n",&n,&m,&p);
	gets(str+1);
	gets(query);
	for(int i = 1;i <= n;i ++){
		if(str[i] == '(') tmp.push(i);
		else{
			int t = tmp.top();
			tmp.pop();
			pos[t] = i;
			pos[i] = t;
		}
	}
	for(int i = 0;i < m;i ++){
		if(query[i] == 'R') r();
		else if(query[i] == 'L') l();
		else del();
	}
	for(int i = 1;i <= n;){
		if(!f[i]) printf("%c",str[i]);
		else i = pos[i];
		i ++;
	}
}