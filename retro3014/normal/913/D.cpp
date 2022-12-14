#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
#define MAX_N 200000


int N, T;
struct S{
	int l, t;
	bool operator <(const S &a){
		return l<a.l;
	}
};
S arr[MAX_N+1];

priority_queue<int, vector<int>, greater<int> > pq;

bool chk(int x){
	while(!pq.empty())	pq.pop();
	for(int i=0; i<N; i++){
		if(arr[i].l>=x)	pq.push(arr[i].t);
	}
	int t = 0;
	while(x--){
		if(pq.empty())	return false;
		t+=pq.top(); pq.pop();
		if(t>T)	return false;
	}
	return true;
}

struct S2{
	int idx, data;
	bool operator <(const S2 &a)const{
		return data>a.data;
	}
};

priority_queue<S2> pq2;

int main(){
	scanf("%d%d", &N, &T);
	for(int i=0; i<N; i++)	scanf("%d %d", &arr[i].l, &arr[i].t);
	int s = 0, e = N, m;
	while(s<e){
		m = (s+e)/2+1;
		if(chk(m))	s = m;
		else	e = m-1;
	}
	printf("%d\n", s);
	printf("%d\n", s);
	while(!pq2.empty())	pq2.pop();
	for(int i=0; i<N; i++){
		if(arr[i].l>=s)	pq2.push({i+1, arr[i].t});
	}
	int t = 0;
	while(s--){
		printf("%d ", pq2.top().idx);
		pq2.pop();
	}
	return 0;
}