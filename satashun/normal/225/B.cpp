#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define pb push_back
#undef debug
int s, k;
vector<int> foo, ans;

int main() {
    scanf("%d %d", &s, &k);
    foo.pb(1);
    int pos = 1;
    while(true){
	int res = 0;
	for(int i = pos - 1; i >= pos - k && i >= 0; i--) res += foo[i];
	foo.pb(res);
	if(res > s) break;
	pos++;
    }
    while(s){
	vector<int>::iterator it = upper_bound(foo.begin(), foo.end(), s);
	ans.pb(*(it - 1));
	s -= *(it - 1);
    }
#ifdef debug
    for(int i = 0; i < foo.size(); i++) printf("%d\n", foo[i]);
    for(int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
#endif
    if(ans.size() == 1) ans.pb(0);
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++){
	printf("%d", ans[i]);
	i != ans.size() - 1 ?printf(" ") : printf("\n");
    }
    return 0;
}