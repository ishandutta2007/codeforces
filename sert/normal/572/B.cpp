#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef int ll;
const int N = 1e5 + 7;

ll n, q, x, y;
char ch;
ll b[N], s[N];
vector <pair<int, int> > v;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
    	cin >> ch >> x >> y;
    	if (ch == 'B')
    		b[x] += y;
    	else
    		s[x] += y;
    }
    for (int i = 0; i < q; i++) {
    	int p = -1;
    	for (int j = 0; j < N; j++)
    		if (s[j] > 0) {
    			if (p == -1)
    				p = j;
    			else if (p > j)
    				p = j;
    		}
    	if (p == -1) 
    		break;
    	else
    		v.push_back(make_pair(p, s[p]));
    	s[p] = 0;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    	cout << "S " << v[i].first << " " << v[i].second << "\n";
    v.clear();
    for (int i = 0; i < q; i++) {
    	int p = -1;
    	for (int j = 0; j < N; j++)
    		if (b[j] > 0) {
    			if (p == -1)
    				p = j;
    			else if (p < j)
    				p = j;
    		}
    	if (p == -1)
    		break;
    	else
    		v.push_back(make_pair(p, b[p]));
    	b[p] = 0;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    	cout << "B " << v[i].first << " " << v[i].second << "\n";
}