#include<cstdio>
#include<iostream>
#include<string>
#include<set>
#include<queue>
using namespace std;


typedef pair<int, char> P;

priority_queue<P, vector<P>, greater<P> > pque;
int cnt[180];
bool block[180];

int main(){
	string str;
	int k;
	fill(block, block + 180, false);
	getline(cin, str);
	cin >> k;
	
	int n = 0;
	for(int i = 0; i < str.length(); i++){
		if(cnt[str[i]] == 0) n ++;
		cnt[str[i]] ++;
	}
	for(char c = 'a'; c <= 'z'; c++){
		if(cnt[c] != 0) pque.push(P(cnt[c], c));
	}
	while(pque.size()){
		P p = pque.top();
		pque.pop();
		if(p.first <= k){
			k -= p.first;
			n--;
			block[p.second] = true;
		}
	}
	printf("%d\n", n);
	for(int i = 0; i < str.length(); i++){
		if(!block[str[i]]) printf("%c", str[i]);
	}
	
	
	return 0;
	
	
}