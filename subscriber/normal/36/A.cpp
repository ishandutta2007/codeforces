#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <math.h>
#include <time.h>

using namespace std;

int n,k=0,a[1000];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d\n",&n);
	for (int i=0;i<n;i++)if (getchar()=='1')a[k++]=i;
	for (int i=2;i<k;i++)if (a[i]-a[i-1]!=a[1]-a[0]){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}