#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>

using namespace std;    

int main() {
    int n, k, t, c = 0;
    scanf("%d%d", &n, &k);
    vector<int> a(1, n + 1), v(n);
    set<int> s;
    for (int i = 1; i <= n; i++)
    	s.insert(i);
    for (int i = 0; i < k; i++) {
    	scanf("%d", &t);
    	v[i] = t;
    	s.erase(t);
    	if (t > a.back()) {
    		printf("-1");
    		return 0;
    	}
    	a.push_back(t);
    	while (a.back() == c + 1) {
    		a.pop_back();
    		c++;
    	}
    }
    for (int i = k; i < n; i++) {
    	t = *--s.lower_bound(a.back());
    	v[i] = t;
    	s.erase(t);
    	a.push_back(t);
    	while (a.back() == c + 1) {
    		a.pop_back();
    		c++;
    	}
    }
    for (int i = 0; i < n; i++)
    	printf("%d ", v[i]);
}