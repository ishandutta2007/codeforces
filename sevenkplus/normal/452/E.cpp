#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 1000010

char s0[N]; int n0; 
int a[N], b[N], ne[N], tp[N]; 

bool cmp0(int x, int y) {return s0[x] < s0[y];}

void sa() {
    for (int i = 0; i < n0; i ++) a[i] = i; 
    sort(a, a+n0, cmp0); 
    b[a[0]] = 0; 
    for (int i = 0; i < n0-1; i ++) {
        b[a[i+1]] = b[a[i]]; 
        if (s0[a[i]] != s0[a[i+1]]) {
            b[a[i+1]] = i+1; 
        }
    }
    for (int l = 1; l < n0; l += l) {
        for (int i = 0; i < n0; i ++) ne[i] = i; 
        for (int i = n0-l; i < n0; i ++) tp[ne[b[i]]++] = i; 
        for (int i = 0; i < n0; i ++) {
            if (a[i] >= l) {
                tp[ne[b[a[i]-l]]++] = a[i] - l; 
            }
        }
        memcpy(a, tp, sizeof tp); 
        tp[a[0]] = 0; 
        for (int i = 0; i < n0-1; i ++) {
            if (a[i] + l < n0 && a[i+1] + l < n0 && 
                b[a[i]] == b[a[i+1]] && 
                b[a[i]+l] == b[a[i+1]+l]) {
                tp[a[i+1]] = tp[a[i]]; 
            } else {
                tp[a[i+1]] = i + 1; 
            }
        }
        memcpy(b, tp, sizeof tp); 
    }
}

int h[N]; 

void ht() {
    int la = 0; 
    for (int i = 0; i < n0; i ++) {
        if (b[i] == n0-1) {
            h[b[i]] = 0; 
            continue; 
        }
        la = max(la-1, 0); 
        int ma = min(n0-i, n0-a[b[i]+1]); 
        while (la < ma && s0[i+la] == s0[a[b[i]+1]+la]) la ++; 
        h[b[i]] = la; 
    }
}

int w[N];

#define P 1000000007
int mn = P;

void input() {
	string s;
	n0 = 0;
	cin >> s;
	mn = min(mn,(int)s.length());
	for (int i = 0; i < (int)s.length(); i ++) {
		w[n0] = 1;
		s0[n0++] = s[i];
	}
	s0[n0++] = 'A';
	cin >> s;
	mn = min(mn,(int)s.length());
	for (int i = 0; i < (int)s.length(); i ++) {
		w[n0] = 2;
		s0[n0++] = s[i];
	}
	s0[n0++] = 'B';
	cin >> s;
	mn = min(mn,(int)s.length());
	for (int i = 0; i < (int)s.length(); i ++) {
		w[n0] = 3;
		s0[n0++] = s[i];
	}
	s0[n0++] = 'C';
	s0[n0+1] = 0;
}

int S[N];
int p[N];

bool cmp(int x, int y) {
	return h[x] > h[y];
}

int mul(int x, int y) {
	return (ll)x*y%P;
}

int mul(int x, int y, int z) {
	return mul(x,mul(y,z));
}

int sub(int x, int y) {
	x -= y;
	if (x < 0) x += P;
	return x;
}

int add(int x, int y) {
	return (x+y)%P;
}

int f[N], f0[N],f1[N],f2[N];
int fa(int x) {
	return f[x] == x?x:(f[x]=fa(f[x]));
}

int main()
{
	input();
	sa(); ht();
	/*
	for (int i = 0; i < n0; i ++) {
		puts(s0+a[i]);
		cout << h[i] << endl;
	}
	*/
	for (int i = 0; i < n0; i ++) p[i] = i;
	sort(p,p+n0,cmp);
	for (int i = 0; i < n0; i ++) {
		f[i] = i;
		f0[i] = f1[i] = f2[i] = 0;
		if (w[i] == 1) f0[i] = 1;
		if (w[i] == 2) f1[i] = 1;
		if (w[i] == 3) f2[i] = 1;
	}
	int j = 0;
	int T = 0;
	for (int i = mn; i >= 1; i --) {
		while (j < n0 && h[p[j]] >= i) {
			int le = a[p[j]], ri = a[p[j]+1];
			le = fa(le); ri = fa(ri);
			T = sub(T, mul(f0[le],f1[le],f2[le]));
			T = sub(T, mul(f0[ri],f1[ri],f2[ri]));
			f0[le] += f0[ri];
			f1[le] += f1[ri];
			f2[le] += f2[ri];
			f0[ri] = 0;
			f1[ri] = 0;
			f2[ri] = 0;
			T = add(T, mul(f0[le],f1[le],f2[le]));
			f[ri] = le;
			j ++;
		}
		S[i] = T;
	}
	for (int i = 1; i <= mn; i ++) 
		printf ("%d%c", S[i], i == mn?'\n':' ');
	return 0;
}