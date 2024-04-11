#include <bits/stdc++.h>
using namespace std;

#define N 200200

const int P = 1e9 + 7, base = 107;

int n, H[N], ex[N];
char s[N];
typedef pair <int, int> pii;
map <pii, vector <int> > mp[N];
map <pii, vector <int> > :: iterator it;

void prep() {
	ex[0] = 1;
	for (int i = 1; i <= n; i ++) {
		H[i] = (1ll * H[i-1] * base + s[i] - 'a' + 1) % P;
		ex[i] = 1ll * ex[i-1] * base % P;
	}
}

pii myhash(int st, int en) {
	return make_pair(((H[en] - 1ll * ex[en-st+1] * H[st-1]) % P + P) % P, en - st + 1);
}

#define V (it->second)

int main() {
	scanf("%d\n", &n);
	gets(s + 1);
	prep();
    for (int i = 1; i <= n; i ++) mp[1][myhash(i,i)].push_back(i);
    int ans = 0;
    for (int i = 1; i <= n; i ++) if (!mp[i].empty()) {
		ans = i;
        for (it = mp[i].begin(); it != mp[i].end(); it ++) {
			int len = it -> first.second, sz = V.size();
			vector <pii> T;
			for (int j = 0; j < sz - 1; j ++) T.push_back(myhash(V[j] + len, V[j+1] - 1));
			for (int st = 0, en = 1; st < sz - 1; st = en, en = st + 1) {
				while (en < sz - 1 && T[en-1] == T[en]) en ++;
				int nxti = i + en - st, nxtlen = V[en] + len - V[st];
				mp[nxti][myhash(V[st],V[st]+nxtlen-1)].push_back(V[st]);
			}
        }
    }
    printf("%d\n", ans);
	return 0;
}