#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 305;

int n;
int a[N][3], mask_a[N], b[N][3], mask_b[N];
int CT[N];

vector< pair<int, int> > ans;;

int main() {
    //freopen("in.txt", "r", stdin);

    int idx[9] = {0}, need[10] = {0}, done[10] = {0};
    memset(CT, -1, sizeof(CT));

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 3; j ++) {
            scanf("%d", &a[i][j]);
            //a[i][j] = rand() % 2;
            mask_a[i] = mask_a[i] << 1 | a[i][j];
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 3; j ++) {
            scanf("%d", &b[i][j]);
            //b[i][j] = rand() % 2;
            mask_b[i] = mask_b[i] << 1 | b[i][j];
        }
        mask_b[i] = mask_b[i] & mask_a[i];
    }
    //printf("ok\n");
    CT[1] = 1;
    for (int i = 2; i <= n; i ++) {
        if (mask_a[i] == 7) {
            ans.push_back(make_pair(1, i));
            // printf("link %d %d\n", 1, i);
            if (idx[ mask_b[i] ] == 0) {
                idx[ mask_b[i] ] = i;
                CT[i] = 1;
            } else {
                CT[i] = 0;
            }
        }
    }
    done[7] = 1;

    while (1) {
        bool moYangGong = true;
        for (int i = 0; i < 8; i ++) {
            if (idx[i]) {
                // printf("M = %d\n", i);
                for (int j = 1; j <= n; j ++) {
                    if (mask_a[j] == i) {
                        // printf("j = %d\n", j);
                        if (idx[ mask_b[j] ] == 0) {
                            idx[ mask_b[j] ] = 1; 
                            //printf("# link %d %d\n", idx[i], j);
                            ans.push_back( make_pair(idx[i], j) );
                            idx[ mask_b[j] ] = j; CT[j] = 1; 
                            moYangGong = false;
                        } else if (done[i] == 0 && CT[j] == -1) {
                            done[i] = 1;
                            //printf("link %d %d\n", idx[i], j);
                            ans.push_back( make_pair(idx[i], j) );
                            CT[j] = 0;
                            moYangGong = false;
                        }
                    } 
                }
            }
        }
        for (int i1 = 0; i1 < 8; i1 ++) {
            for (int i2 = i1+1; i2 < 8; i2 ++) {
                if ( (idx[i1] > 0) && (idx[i2] > 0) ) {
                    int i = i1 | i2;
                    for (int j = 1; j <= n; j ++) {
                        if (mask_a[j] == i) {
                            if (idx[ mask_b[j] ] == 0) {
                                idx[ mask_b[j] ] = 1;
                                //printf("link %d %d, %d %d\n", idx[i1], j, idx[i2], j);
                                ans.push_back( make_pair(idx[i1], j) );
                                ans.push_back( make_pair(idx[i2], j) );
                                idx[ mask_b[j] ] = j; CT[j] = 1; 
                                moYangGong = false;
                            } else if (done[i] == 0 && CT[j] == -1) {
                                done[i] = 1;
                                //printf("link %d %d, %d %d\n", idx[i1], j, idx[i2], j);
                                ans.push_back( make_pair(idx[i1], j) );
                                ans.push_back( make_pair(idx[i2], j) );
                                CT[j] = 0;
                                moYangGong = false;
                            }
                        }
                    }   
                }
            }
        }
        for (int i = 1; i <= n; i ++) {
            if (CT[i] == 0) {
                for (int j = 1; j <= n; j ++) {
                    if (CT[j] == -1) {
                        if ( mask_a[i] == mask_a[j] ) {
                            //printf("link : %d %d\n", i, j);
                            ans.push_back(make_pair(i, j));
                            CT[j] = 1;
                            moYangGong = false;
                        }
                    }
                }
            }
        }
        if (moYangGong == true) break;
    }
    for (int i = 1; i <= n; i ++) {
        if (CT[i] == -1) return !printf("Impossible\n");
    }
    printf("Possible\n");
    for (int i = 1; i <= n; i ++) {
        printf("%d ", CT[i]);
    }
    printf("\n");
    printf("%d\n", (int)ans.size());
    for (auto p: ans) {
        printf("%d %d\n", p.first, p.second);
    }
}