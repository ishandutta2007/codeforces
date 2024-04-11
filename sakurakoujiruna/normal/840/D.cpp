#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int N = 3e5L + 11;

int cnt = 0;

int a[N];
vector <int> v[N];
int f(const vector <int> &v, int x) { //cnt ++;

	int l = 0, r = v.size() + 1;
	while(l + 1 < r) {
		int m = (l + r) >> 1;
		if(v[m - 1] <= x)
			l = m;
		else
			r = m;
	}
	return l;
}

bool sp[N];

const int M = 80;
int his[M];

inline int read()    
{    
    char ch;  
    bool flag = false;  
    int a = 0;    
    while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));    
    if(ch != '-')  
    {  
        a *= 10;  
        a += ch - '0';    
    }  
    else  
    {  
        flag = true;  
    }  
    while(((ch = getchar()) >= '0') && (ch <= '9'))  
    {  
        a *= 10;  
        a += ch - '0';  
    }     
    if(flag)  
    {  
        a = -a;  
    }  
    return a;    
}

using ull = unsigned long long;
//mt19937 myrand(114514);
unsigned Rand() { static unsigned x = time(0);
	return x ^= x << 13, x ^= x >> 17, x ^= x << 5; }
#define myrand Rand

int main() {
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		int x; /*scanf("%d", &x);*/ x = read(); a[i] = x;
		v[x].pb(i);
	}
	
	//bool ff = (v[1].size() >= 4) && (v[1][0] == 1) && (v[1][1] == 2) && (v[1][2] == 3) && (v[1][3] == 4) && (rand() % 2 == 1);
	
	for(int s = 1; s <= q; s ++) {
		int l, r, k; //scanf("%d%d%d", &l, &r, &k);
		l = read(); r = read(); k = read();
		int ans = n + 1, lim = (r - l + 1) / k + 1;
		
		for(int _ = 0; _ < M; _ ++) {
			int i = a[myrand() % (r - l + 1) + l]; his[_] = i;
			if(sp[i]) continue; sp[i] = 1;
			int t = f(v[i], r);
			if(t >= lim && t - f(v[i], l - 1) >= lim)
				ans = min(ans, i);
		}
		for(int x : his) sp[x] = 0;
		/*
		if(ff) {
			if(s == 221) {
				cout << l << ' ' << r << ' ' << k << '\n';
				cout << f(v[2], r) - f(v[2], l - 1) << '\n';
			}
			continue;
		}
		*/
		if(ans == n + 1)
			printf("-1\n");
		else
			printf("%d\n", ans);
			
	}
	//cout << cnt << '\n'; // 3
}