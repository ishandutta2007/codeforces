#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, int> P;

priority_queue<P, vector<P>, greater<P> > pque;

int s[200050],g[200050];
int num[200050];


int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &s[i], &g[i]);
		num[i] = s[i] + g[i];
		pque.push(P(num[i], i));
	}
	while(!pque.empty()){
		P p = pque.top();
		pque.pop();
		int i = p.second;
		if(p.first > num[i]) continue;
		for(int j = i - 1; j >= 0; j--){
			if(num[j] > num[i] + (i-j)) num[j] = num[i] + (i-j);
			else break;
		}
		for(int j = i + 1; j < n; j++){
			if(num[j] > num[i] + (j-i)) num[j] = num[i] + (j-i);
			else break;
		}
		
	}
	long long sum = 0;
	for(int i = 0; i < n; i++){
		if(num[i] < s[i]) return !printf("-1");
		sum += (num[i] - s[i]);
	}
	cout << sum << endl;
	for(int i = 0; i < n; i++){
		printf("%d ", num[i]);
	}
	
	
}