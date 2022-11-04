#include <cstdio>
#include <map>
#define le (i << 1)
#define ri (i << 1 | 1)
using namespace std;
const int N = 1e6 + 1, L = 18;

int t, l, r, a[N];
map<int, int> cnt, mp;

int main(){
	scanf("%d", &t);
	while(t--){
		cnt.clear();
		mp.clear();
		scanf("%d%d", &l, &r);
		int j = 0;
		while(!((l >> j) & 1) && ((r >> j) & 1)) j++;
		for(int i = l; i <= r; i++){
			scanf("%d", &a[i]);
			if(cnt[a[i] >> (j + 1)] == (1 << j))
				mp.erase(a[i] >> (j + 1));
			else{
				cnt[a[i] >> (j + 1)]++;
				mp[a[i] >> (j + 1)] = a[i];
			}
		}
		int candidate = mp.begin() -> second;
		int x = candidate ^ l;
		bool flag = true;
		for(int i = l; flag && i <= r; i++)
			if((a[i] ^ x) < l || (a[i] ^ x) > r) flag = false;
		printf("%d\n", flag ? x : (candidate ^ r));
	}
	return 0;
}