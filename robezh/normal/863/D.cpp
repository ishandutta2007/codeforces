#include<cstdio>
#include<iostream>
using namespace std;

const int MAXn = 200005;
const int MAXq = 200005;

int nums[MAXn];
int query[MAXq][3];
int p[105];

int main() {
    int n,q,m;
    scanf("%d %d %d", &n, &q, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d",&nums[i]);
    }
    for(int i = 0; i < q; i++) {
        scanf("%d%d%d", &query[i][0], &query[i][1], &query[i][2]);
    }
    for(int i = 1; i <= m; i++) scanf("%d", &p[i]);
    for(int i = q - 1; i >= 0; i--) {
//    	for(int k = 1; k <= m; k++) {
//            printf("%d ", p[k]);
//        }
//        printf("\n");
        int l = query[i][1];
        int r = query[i][2];
        if(query[i][0] == 1) {
            for(int j = 1; j <= m; j++) {
                if(p[j] >= l && p[j] <= r) {
                	//printf("p[%d] wil change\n",j);
                    p[j] -= 1;
                    if(p[j] < l) p[j] += r - l + 1;
                }
            }
        }
        else if(query[i][0] == 2) {
            for(int j = 1; j <= m; j++) {
                if(p[j] >= l && p[j] <= r) {
                    p[j] = l + r - p[j];
                }
            }
        }
        
    }
    for(int i = 1; i <= m; i++) {
        printf("%d ", nums[p[i]]);
    }
}