#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

#define NN 1000100

char S1[NN], S2[NN];
char B[NN*3];
int fail[NN*3];

void build_fail_function(char B[], int len) {
    int j = fail[0] = -1;
    for (int i = 1; i < len; i ++) {
        while (j != -1 and B[j + 1] != B[i]) j = fail[j];
        if (B[j + 1] == B[i]) j ++;
        fail[i] = j;
    }
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	gn(n);
	n--;
	scanf("%s %s", S1, S2);
	
	for(int i=0; i<n; i++) {
		if(S1[i] == 'N') S1[i] = 'S';
		else if(S1[i] == 'S') S1[i] = 'N';
		else if(S1[i] == 'W') S1[i] = 'E';
		else S1[i] = 'W';
	}
	
	int nn = 0;
	for(int i=0; i<n; i++) B[nn++] = S1[n-i-1];
	B[nn++] = '*';
	for(int i=0; i<n; i++) B[nn++] = S2[i];
	
	build_fail_function(B, nn);
	if(fail[nn-1] == -1) return puts("YES");
	puts("NO");
	
}