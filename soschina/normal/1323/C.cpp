#include <cstdio>
using namespace std;
const int N = 1e6 + 1;

int n, cnt, ans;
char s[N];

int main(){
	scanf("%d%s", &n, s);
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			if(cnt < 0) ans++;
			cnt++;
		}else{
			cnt--;
			if(cnt < 0) ans++;
		}
	}
	printf("%d", cnt ? -1 : ans);
	return 0;
}