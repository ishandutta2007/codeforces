#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

map<int, int> time;

struct doc{
	int start;
	int inter;
}docs[1005];

//bool cmp(doc d1, doc d2){
//	return d1.start == d2.start ? d1.inter > d2.inter : d1.start < d2.start;
//}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &docs[i].start, &docs[i].inter);
	}
//	sort(docs, docs+n, cmp);
	int maxtime = 0;
	for(int i = 0; i < n; i++){
		int time = (int)ceil((maxtime + 1 - docs[i].start) / (double)docs[i].inter);
		time = max(0, time);
		maxtime = time * docs[i].inter + docs[i].start;
	}
	printf("%d",maxtime);
}