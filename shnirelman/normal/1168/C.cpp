#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int A = 26;
const int N = 3e5 + 13;
const int M = 53;
const int K = 20;

int a[N];
int lf[N][K];
int lst[K];

int main() {
    int n, q;
    cin >> n >> q;

	for(int i = 0; i < n; i++)
		cin >> a[i];

    for(int i = 0; i < K; i++)
		lst[i] = -1;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < K; j++)
			lf[i][j] = -1;

    for(int i = 0; i < n; i++) {
		for(int j = 0; j < K; j++)
			if((1 << j) & a[i]) if(lst[j] > -1) {
				lf[i][j] = lst[j];
                for(int k = 0; k < K; k++)
					lf[i][k] = max(lf[i][k], lf[lst[j]][k]);
			}

//		for(int j = 0; j < 4; j++)
//			cout << lf[i][j] << ' ';
//		cout << endl;

		for(int j = 0; j < K; j++)
			if((1 << j) & a[i]) {
				lst[j] = i;
			}
    }

    for(int ind = 0; ind < q; ind++) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        bool res = false;
        for(int i = 0; i < K; i++)
			if(((1 << i) & a[x]) > 0 && lf[y][i] >= x)
				res = true;

		cout << (res ? "Shi" : "Fou") << endl;

    }

//	vector<pair<pii, int>> b(q);
//    for(int i = 0; i < q; i++) {
//		cin >> b[i].f.s >> b[i].f.f;
//		b[i].s = i;
//    }
//
//    sort(b.begin(), b.end());
//
//    for(int i = 0; i < q; i++) {
//
//    }

}