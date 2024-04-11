#include <bits/stdc++.h>
using namespace std;

#define N 500001

const int D = 777;

int a[N], s[D][D];

inline char nc() {
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
template <class T> inline void read(T &x){
	char c=nc(),b=1;
	for (;!(c>='0'&&c<='9'||c==EOF);c=nc()) if (c=='-') b=-b;
	for (x=0;c>='0'&&c<='9';x=x*10+c-'0',c=nc()); x*=b;
}
template <typename Head, typename... Tail>
inline void read(Head& H, Tail&... T) {
    read(H), read(T...);
}

int main() {
    int q;
    read(q);
    while (q --) {
        int ty, x, y;
        read(ty, x, y);
        if (ty == 1) {
            for (int i = 1; i < D; i ++) s[i][x%i] += y;
            a[x] += y;
        }
        else {
            if (x < D) printf("%d\n", s[x][y]);
            else {
                int sum = 0;
                for (int i = y; i < N; i += x) sum += a[i];
                printf("%d\n", sum);
            }
        }
    }

}