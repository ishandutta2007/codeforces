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

using namespace std;

#define maxn 100500

int sum[maxn];
char s[maxn];
char stack[maxn];
int p[maxn];
int num, mx;
int l, r;
//int lastl, lastr, lastk;
int endi[maxn];
int ll[maxn], rr[maxn];

bool ok(char a, char b){
	return(a == '(' && b == ')' || a == '[' && b == ']');
}

int main(){
	scanf("%s", s);
	int n = strlen(s);
	num = l = r = 0;
	mx -= 1;
	/*lastl = lastr = -100;
	lastk = -100;*/
	sum[0] = 0;
	for(int i = 0; i < n; ++i){
		endi[i] = -100;
		sum[i + 1] = sum[i];
		if(s[i] == ']')++sum[i + 1];
		if(s[i] == '(' || s[i] == '[' || num == 0 || !ok(stack[num], s[i])){
			stack[++num] = s[i];
			p[num] = i + 1;
		}
		else{
			endi[i] = p[num] - 1;
			/*(mx < sum[i + 1] - sum[p[num]]){
				mx = sum[i + 1] - sum[p[num] - 1];
				l = p[num] - 1;
				r = i;
			}*/
			--num;
			/*if(num == 0)
				if(lastr + 1 == p[num + 1] - 1){
					lastk += sum[i + 1] - sum[p[num + 1]];
					lastr = i;
				}
				else{
					if(mx < lastk){
						mx = lastk;
						l = lastl;
						r = lastr;
					}
					lastl = p[num + 1] - 1;
					lastr = i;
					lastk = sum[i + 1] - sum[p[num + 1]];
				}
				*/
		}
		//printf("%d : l %d r %d k %d num = %d\n", i, lastl, lastr, lastk, num);
	}
	/*if(mx < lastk){
		mx = lastk;
		l = lastl;
		r = lastr;
	}*/
	for(int i = 0; i < n; ++i){
		if(endi[i] >= 1 && endi[endi[i] - 1] >= 0){
			endi[i] = endi[endi[i] - 1];
		}
		//printf("i = %d, endi = %d\n", i, endi[i]);
		if(endi[i] >= 0 && mx < sum[i + 1] - sum[endi[i]]){
			mx = sum[i + 1] - sum[endi[i]];
			l = endi[i];
			r = i;
		}
	}	
	if(mx == -1)
		printf("0\n");
	else{
		printf("%d\n", mx);
		for(int i = l; i <= r; ++i)
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}