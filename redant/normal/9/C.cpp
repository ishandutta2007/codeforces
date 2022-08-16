#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
using namespace std;
typedef long long LL;

set<int> S;
int r = 0, N;

void go(int cn)
{
	if(cn<0 || cn>N) return;
	if(cn>=1 && cn<=N) S.insert(cn);
	go(cn*10+1); 
	if(cn!=0) go(cn*10);
}

int main()
{
	scanf("%d",&N);
	go(0); go(1);
	printf("%d",S.size());
	return 0;
}