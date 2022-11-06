#include <cstdio>
using namespace std;
const int N = 101;

int t, n, a[N] = {1}, ans = 1;
bool die;

int main(){
	scanf("%d", &t);
	while(t--){
		die = false;
		ans = 1;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			if(!a[i] && !a[i - 1]) die = true;
			else if(a[i]){
				if(i > 1 && a[i - 1]) ans += 5;
				else ans++;
			}
		}
		printf("%d\n", die ? -1 : ans);
	}
	return 0;
}