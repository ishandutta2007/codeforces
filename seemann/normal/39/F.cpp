#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int a[200],b[200];
int ans[200];
int ans_k;
int res=500;

int main()
{
    int n,m,k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i=0; i<m; ++i) scanf("%d", &a[i]);
    for (int i=0; i<k; ++i) scanf("%d", &b[i]);

    for (int i=0; i<m; ++i) {
        int t = 0;
        for (int j=0; j<k; ++j)
            if (b[j]%a[i]==0) ++t;

        if (t<res) {
            res = t; ans_k=1; ans[0] = i+1;
        } else
        if (t==res) {
            ans[ans_k++] = i+1;
        }
    }

    printf("%d\n", ans_k);
    for (int i=0; i<ans_k; ++i) printf("%d ", ans[i]);
    return 0;
}