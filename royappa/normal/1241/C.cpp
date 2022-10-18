#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

bool bonusLT(pii x, pii y) {
    return x.second < y.second;
}

void run(int n, vector<int> &price, int x, int a, int y, int b, LL tot) {
    sort(price.rbegin(), price.rend());
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    int lo = 0, hi = n+1; // First lo tickets cannot suffice, and first hi tickets will suffice
    bool pass = false;
    while (lo+1 != hi) {
        int mid = lo+(hi-lo)/2;
        vector<pii> best;
        int p = 0;
        int nXY = 0, nX = 0, nY = 0;
        for (int i = 0; i < mid; i++) {
            int bonus = 0;
            if ((i+1)%a == 0 && (i+1)%b == 0) nXY++;
            else if ((i+1)%a == 0) nX++;
            else if ((i+1)%b == 0) nY++;
        }
        LL sum = 0;
        for (int i = 0; i < mid; i++) {
            LL bonus = 0;
            if (nXY) {
                bonus = x+y;
                nXY--;
            }
            else if (nX) {
                bonus = x;
                nX--;
            }
            else if (nY) {
                bonus = y;
                nY--;
            }
            sum += LL(price[i])*bonus/100;
        }
        if (sum >= tot) {
            pass = true;
            hi = mid;
        }        
        else {
            lo = mid;
        }        
    }
    cout << (pass ? hi : -1) << endl;
}

int main()
{
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int n;
        scanf("%d", &n);
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }
        int x, a;
        scanf("%d%d", &x, &a);
        int y, b;
        scanf("%d%d", &y, &b);
        LL tot;
        cin >> tot;
        run(n, p, x, a, y, b, tot);
	}
	exit(0);
}