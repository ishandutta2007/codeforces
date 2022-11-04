#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int N = 2e5 + 2;

int t, n, m, a, ans, line, x, y;
vector<int> vec[N];

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		scanf("%d", &n);
		m = 1;
		vec[m].clear();
		vec[m].push_back(0);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a);
			if(a == 0){
				vec[++m].clear();
				vec[m].push_back(0);
			}
			else vec[m].push_back(a);
		}
		for(int i = 1; i <= m; i++){
			int cntneg = 0, cnt = 0;
			for(int j = 1; j < vec[i].size(); j++){
				if(vec[i][j] < 0) cntneg ^= 1;
				if(abs(vec[i][j]) == 2) cnt++;
			}
			if(!cntneg){
				if(cnt > ans){
					ans = cnt;
					line = i;
					x = 1;
					y = 0;
				}
				continue;
			}
			int cntl = 0, cntr = 0, l = 1, r = 0;
			for(int j = 1; j < vec[i].size(); j++){
				if(abs(vec[i][j]) == 2) cntl++;
				if(vec[i][j] < 0){
					l = j + 1;
					break;
				}
			}
			for(int j = vec[i].size() - 1; j > 0; j--){
				if(abs(vec[i][j]) == 2) cntr++;
				if(vec[i][j] < 0){
					r = vec[i].size() - j;
					break;
				}
			}
			if(cntl < cntr){
				if(cnt - cntl > ans){
					ans = cnt - cntl;
					line = i;
					x = l;
					y = 0;
				}
			}
			else{
				if(cnt - cntr > ans){
					ans = cnt - cntr;
					line = i;
					x = 1;
					y = r;
				}
			}
		}
		if(ans == 0){
			printf("0 %d\n", n);
			continue;
		}
		for(int i = 1; i < line; i++)
			x += vec[i].size();
		for(int i = m; i > line; i--)
			y += vec[i].size();
		printf("%d %d\n", x - 1, y);
	}
	return 0;
}