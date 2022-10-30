#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		string s;
		cin >> s;
		int one = 0;
		for(i=0; i<n; i++) {
            one += s[i]-'0';
		}
		if(((long long)one*m)%n == 0) {
            int count = 0;
            for(i=0; i<m; i++) {
                count += s[i]-'0';
            }
            for(i=0; i<n; i++) {
                if(count == (long long)one*m/n) {
                    if(i <= n-m) {
                        printf("1\n");
                        printf("%d %d\n", i+1, i+m);
                    } else {
                        printf("2\n");
                        printf("%d %d\n", 1, i+m-n);
                        printf("%d %d\n", i+1, n);
                    }
                    break;
                }
                count -= s[i]-'0';
                count += s[(i+m)%n]-'0';
            }
		} else {
		    printf("-1\n");
		}
	}
}