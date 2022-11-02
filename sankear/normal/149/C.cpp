#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

#define mp make_pair

pair <int, int> a[100100];
int lst1[100100], lst2[100100];

int main(){
    //freopen("rifleman.in", "r", stdin);
    //freopen("rifleman.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int maxa = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].first);
		a[i].second = i;
		maxa = max(maxa, a[i].first);
	}
	sort(a, a + n);
	int sum1 = 0, sz1 = 0, sum2 = 0, sz2 = 0;
	for(int i = 0; i < n; i++){
		if(abs(sum1 + a[i].first - sum2) > maxa){
			sum2 += a[i].first;
			lst2[sz2++] = a[i].second;
			continue;
		}
		if(abs(sum1 - sum2 - a[i].first) > maxa){
			sum1 += a[i].first;
			lst1[sz1++] = a[i].second;
			continue;
		}
		if(sz1 < sz2){
			lst1[sz1++] = a[i].second;
		}
		else{
			lst2[sz2++] = a[i].second;
		}
	}
	printf("%d\n", sz1);
	for(int i = 0; i < sz1; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%d", lst1[i] + 1);
	}
	printf("\n%d\n", sz2);
	for(int i = 0; i < sz2; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%d", lst2[i] + 1);
	}
	printf("\n");
	return 0;
}