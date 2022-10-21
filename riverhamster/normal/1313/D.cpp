#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}
const int N = 100005;
int pos[N * 2], pc = 0;
int l[N], r[N];
int f[N * 2][(1 << 8) + 5];
vector<int> In[N * 2];
int poc[260];

int main(){
	// File("d");
	int n, m, K;
	gi(n); gi(m); gi(K);
	for(int i=1; i<=n; i++){
		gi(l[i]); gi(r[i]); ++r[i];
		pos[++pc] = l[i]; pos[++pc] = r[i];
	}
	sort(pos+1, pos+1+pc);
	pc = unique(pos+1, pos+1+pc) - pos - 1;
	for(int i=1; i<=n; i++){
		l[i] = lower_bound(pos+1, pos+1+pc, l[i]) - pos;
		r[i] = lower_bound(pos+1, pos+1+pc, r[i]) - pos;
		for(int j=l[i]; j<r[i]; j++) In[j].push_back(i);
	}
	const int U = (1 << K) - 1;
	for(int i=1; i<=U; i++)
		poc[i] = poc[i >> 1] + (i & 1);
	int lstU = 0;
	for(int i=1; i<pc; i++){
		// printf("i %d : [%d, %d)\n", i, pos[i], pos[i+1]);
		// sort(In[i].begin(), In[i].end());
		// for(int v : In[i]) printf("%d ", v);
		// puts("");
		int last[10];
		int nU = (1 << In[i].size()) - 1;
		fill(last, last+K, -1);
		unsigned pi = 0, pl = 0;
		while(pi < In[i].size() && pl < In[i-1].size()){
			if(In[i][pi] == In[i-1][pl]){
				last[pl] = pi;
				++pi; ++pl;
			}
			else if(In[i][pi] > In[i-1][pl]) ++pl;
			else ++pi;
		}
		int mp[256 + 5];
		fill(mp, mp+U+1, -1);
		for(int S=0; S<=lstU; S++){
			int now = 0;
			for(int j=0; j<K; j++)
				if(((S >> j) & 1) && last[j] != -1)
					now |= 1 << last[j];
			upmax(mp[now], f[i-1][S]);
		}
		int Lst = 0;
		for(int j=0; j<K; j++)
			if(last[j] != -1) Lst |= (1 << last[j]);
		// printf("Lst = %d\n", Lst);
		// printf("nU = %d\n", nU);
		for(int S=0; S<=nU; S++){
			if(mp[S] == -1) continue;
			// puts("Continued");
			int D = nU ^ Lst;
			// printf("D = %d\n", D);
			for(int now=D; now>=0; --now){
				now &= D;
				if((poc[now] ^ poc[S]) & 1) upmax(f[i][S | now], mp[S] + pos[i+1] - pos[i]);
				else upmax(f[i][S | now], mp[S]);
				// printf("f[%d] : %d\n", S | now, f[i][S | D]);
			}
		}
		lstU = nU;
	}
	int res = 0;
	for(int i=0; i<=U; i++)
		res = max(res, f[pc-1][i]);
	printf("%d\n", res);
	return 0;
}