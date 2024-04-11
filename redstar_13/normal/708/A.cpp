#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

typedef pair<int, int> pii;
typedef long long INT;

template <class T> inline void smin(T &a, T b) {if (a>b) a=b;}
template <class T> inline void smax(T &a, T b) {if (a<b) a=b;}

char s[111111];

int main() {
	
	int i, len;
	scanf("%s", s);
	len=strlen(s);
	for (i=0; i<len; i++) {
		if (s[i]!='a') {
			for (int j=i; j<len; j++) {
				if (s[j]=='a') break;
				s[j]=s[j]-1;
			}
			break;
		}
	}
	if (i==len) {
		s[len-1]='z';
	}
	puts(s);
	
	return 0;
}