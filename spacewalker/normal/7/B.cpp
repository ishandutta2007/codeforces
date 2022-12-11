#include <bits/stdc++.h>

using namespace std;

int main() {
    static char opt[20];
    int t, m; scanf("%d %d", &t, &m);
    vector<int> memory(m, -1);
    int cBlockID = 1;
    for (int i = 0; i < t; ++i) {
        scanf("%s", opt);
        if (opt[0] == 'a') {
            int sz; scanf("%d", &sz);
            bool allocated = false;
            for (int i = 0, j = 0; i < m; i = j) {
                if (memory[i] != -1) {
                    ++j;
                    continue;
                }
                while (j < m && memory[j] == -1) ++j;
                if (j - i >= sz) {
                    allocated = true;
                    for (int k = i; k < i + sz; ++k) memory[k] = cBlockID;
                    break;
                }
            }
            if (allocated) printf("%d\n", cBlockID++);
            else printf("NULL\n");
        } else if (opt[0] == 'd') {
            stable_sort(begin(memory), end(memory), [&] (int x, int y) {
                    return int(x == -1) < int(y == -1);
            });
        } else { // erase
            int blk; scanf("%d", &blk);
            bool erased = false;
            if (blk > 0) {
                for (int &v : memory) if (v == blk) {
                    erased = true;
                    v = -1;
                }
            }
            if (!erased) printf("ILLEGAL_ERASE_ARGUMENT\n");
        }
//        for (int v : memory) printf("%d ", v);
//        printf("\n");
    }

}