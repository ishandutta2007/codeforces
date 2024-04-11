#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 102;

int t, n, a[N], b[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int cnta = 0, cntb = 0, cntc = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            cnta += a[i];
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &b[i]);
            cntb += b[i];
            if(a[i] != b[i])
                cntc++;
        }
        printf("%d\n", min(abs(cnta - cntb) + 1, cntc));
    }
	return 0;
}