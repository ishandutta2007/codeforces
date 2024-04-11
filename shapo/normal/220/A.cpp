#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

#define maxn 100500

using namespace std;

int n;
int a[maxn], srt[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		srt[i] = a[i];
	}
	sort(srt, srt + n);
	int count = 0;
	for(int i = 0; i < n; ++i)
		if(srt[i] != a[i])++count;
	if(count > 2)
		printf("NO\n");
	else
		printf("YES\n");

	return 0;
}