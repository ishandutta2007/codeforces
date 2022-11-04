#include <cstdio>
#include <set>
using namespace std;

unsigned int t, n, s, k, a;

int main(){
	scanf("%u", &t);
	while(t--){
		set<unsigned int> st;
		scanf("%u%u%u", &n, &s, &k);
		while(k--){
			scanf("%u", &a);
			st.insert(a);
		}
		for(unsigned int i = 0; s > i || s + i <= n; i++)
			if((s > i && st.find(s - i) == st.end()) || (s + i <= n && st.find(s + i) == st.end())){
				printf("%u\n", i);
				break;
			}
	}
	return 0;
}