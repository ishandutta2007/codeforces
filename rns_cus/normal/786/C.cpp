#include<bits/stdc++.h>
using namespace std;

#define N 100010

int a[N], n, ans[N], id[N], nxt[N];
vector <int> v[N];
int tree[N];

void update(int k, int val){ for(; k <= n; k += k & -k) tree[k] += val; }

int find(int x){
	int pos = 0, sum = 0;
	for(int bit = (1 << 18); bit >= 1; bit >>= 1){
		if(pos + bit <= n && sum + tree[pos + bit] < x){
			pos += bit;
			sum += tree[pos];
		}
	} return pos;
}


int main(){
   // freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){ id[i] = n + 1; };
	for(int i = 1; i <= n; i ++){
		scanf("%d", a + i);
	}
	for(int i = n; i >= 1; i --){
        nxt[i] = id[a[i]];
        id[a[i]] = i;
	}
	for(int i = 1; i <= n; i ++) if(id[i] != n + 1) update(id[i], 1);
    for(int i = 1; i <= n; i ++){
        int t = find(i + 1);
        v[t].push_back(i);
    }
	for(int i = 1; i <= n; i ++){
		update(i, -1);
		update(nxt[i], 1);
		for(int j = 0; j < v[i].size(); j ++){
            int d = v[i][j];
            ans[d] ++;
            int t = find(d + 1);
            int t1 = find(d);
            int t2 = find(d + 2);
            if(t > i) v[t].push_back(d);
		}
		v[i].clear();
	}
	for(int i = 1; i <= n; i ++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
}