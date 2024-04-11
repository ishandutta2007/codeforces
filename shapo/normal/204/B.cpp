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

#define maxn 300500

using namespace std;

int cur[maxn][2];
int n, res = 1e9;
int tmp[maxn];
int num;

int main(){
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &cur[i][0], &cur[i][1]);
		tmp[num++] = cur[i][0];
		tmp[num++] = cur[i][1];
	}
	sort(tmp, tmp + num);
	int l = 0;
	for(int i = 1; i <= num; ++i){
		if(i == num || tmp[l] != tmp[i]){
			int len = i - l;
			if(len >= (n + 1) / 2){
				int pr = 0, rev = 0;
				for(int j = 0; j < n; ++j)
					if(cur[j][0] == tmp[l])++pr;
					else
						if(cur[j][1] == tmp[l])++rev;
				if(pr + rev >= (n + 1) / 2)res = min(res, max(((n + 1) / 2) - pr, 0));
			}
			l = i;
		}
	}

	if(res == 1e9)res = -1;
	printf("%d\n", res);

	return 0;
}