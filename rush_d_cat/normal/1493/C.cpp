#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, k; string s;

int chk(int pos, int c[]) {
	int rem = n - 1 - pos;
	int need = 0;
	//for (int i=0;i<26;i++) cout<<c[i];cout<<endl;
	for (int i = 0; i < 26; i ++)
		need += (k-c[i]%k)%k;
	return need <= rem && (rem - need) % k == 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T; cin >> T;
    while (T --) {
    	cin >> n >> k >> s;
    	int c[27] = {0};
   		bool done = 0;
   		vector<char> ans;

    	for (int i = 0; i < n; i ++) {
    		c[s[i]-'a'] ++;
    	}

    	if (chk(n-1, c)) {
    		cout << s << endl; continue;
    	}
    	bool ok = 0;

    	for (int i = n - 1; i >= 0; i --) {
    		c[s[i] - 'a'] --;
    		int cur = s[i] - 'a';
    		for (int j = cur + 1; j < 26; j ++) {
    			c[j] ++;
    			if (chk(i, c)) {
    				ok = true;
    				for (int x = 0; x < i; x ++) cout << s[x];
    				cout << (char)('a' + j);
    				//cout << endl;
    				vector<char> tmp;

    				for (int x = 0; x < 26; x ++) {
    					int cur = (k-c[x]%k)%k;
    					while (cur --) tmp.push_back('a'+x);
    				}
    				int rem = n - 1 - i;
    				while (tmp.size() < rem) tmp.push_back('a');
    				sort(tmp.begin(), tmp.end());
    				for (auto c: tmp) cout << c;
    				cout << endl;

    				break;
    			}
    			c[j] --;
    		}
    		if (ok == true) break; 
    	}
    	if (!ok) cout << -1 << endl;

    }
}