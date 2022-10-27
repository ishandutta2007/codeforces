#include <iostream>
#include <set>
using namespace std;
int n, m;
char s[102][102];
set<int> st;
int main() {
    scanf("%d %d", &n, &m);

    for(int i=1;i<=n;i++) {
        scanf("%s", s[i]+1);
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            st.insert(s[i][j]);
        }
    }

    int can = 0;

    if(n % 3 == 0) {
        int ok = 1;
        for(int i=1;i<=n/3;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i][j] != s[1][1]) ok = 0;
            }
        }
        for(int i=n/3+1;i<=n/3*2;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i][j] != s[n/3+1][1]) ok = 0;
            }
        }
        for(int i=n/3*2+1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s[i][j] != s[2*n/3+1][1]) ok = 0;
            }
        }
        if(ok) can = 1;
    } 

    if(m % 3 == 0) {
        int ok = 1;
        for(int i=1;i<=m/3;i++) {
            for(int j=1;j<=n;j++) {
                if(s[j][i] != s[1][1]) ok = 0;
            }
        }

        for(int i=m/3+1;i<=m/3*2;i++) {
            for(int j=1;j<=n;j++) {
                if(s[j][i] != s[1][m/3+1]) ok = 0;
            }
        }

        for(int i=m/3*2+1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(s[j][i] != s[1][m/3*2+1]) ok = 0;
            }
        }
        if(ok) can = 1;
    } 

    printf("%s\n", can&&(st.size()==3)?"YES":"NO");

}