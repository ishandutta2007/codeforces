#include <bits/stdc++.h>
using namespace std;

#define N 300005

vector <int> v[N];
int n, q, a[N];

char nc() {
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
void read(int &x){
	char c=nc(),b=1;
	for (;!(c>='0'&&c<='9'||c==EOF);c=nc()) if (c=='-') b=-b;
	for (x=0;c>='0'&&c<='9';x=x*10+c-'0',c=nc()); x*=b;
}

int main() {
    mt19937 Rand; Rand.seed(time(0));
    read(n), read(q);
    for (int i = 1; i <= n; i ++) {
		read(a[i]);
		v[a[i]].push_back(i);
    }
    while (q --) {
		int l, r, k;
		read(l), read(r), read(k);
        int mn = (r - l + 1) / k + 1;
        int ans = n + 10;
        for (int i = 0; i < 80; i ++) {
            int x = (Rand()) % (r - l + 1) + l;
			int t = a[x];
			if (ans <= t) continue;
			int g = lower_bound(v[t].begin(), v[t].end(), l) - v[t].begin();
			if (g + mn <= v[t].size() && v[t][g+mn-1] <= r) ans=t;
        }
        if (ans > n) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}