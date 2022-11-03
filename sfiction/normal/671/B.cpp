#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 5E5 + 10;

int n, k;
int c[MAXN];

int main(){
	scanf("%d%d", &n, &k);
	ll sum = 0;
	for (int i = 0; i < n; ++i){
		scanf("%d", &c[i]);
		sum += c[i];
	}
	ll avg = sum / n, s1 = 0, s2 = 0;
	vector<int> a, b;
	for (int i = 0; i < n; ++i){
		if (c[i] <= avg){
			s1 += avg - c[i];
			a.push_back(c[i]);
		}
		else{
			s2 += c[i] - avg - 1;
			b.push_back(c[i]);
		}
	}
	if (sum % n == 0 && s1 <= k){
		puts("0");
		return 0;
	}

	a.push_back(avg);
	b.push_back(avg + 1);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	int low = a[0], t = k;
	for (int i = 1; i < a.size(); ++i){
		if (t / i >= a[i] - a[i - 1]){
			low = a[i];
			t -= i * (a[i] - a[i - 1]);
		}
		else{
			low = a[i - 1] + t / i;
			break;
		}
	}
	int high = b[0];
	t = k;
	for (int i = 1; i < b.size(); ++i){
		if (t / i >= b[i - 1] - b[i]){
			high = b[i];
			t -= i * (b[i - 1] - b[i]);
		}
		else{
			high = b[i - 1] - t / i;
			break;
		}
	}
	printf("%d\n", high - low);
	return 0;
}