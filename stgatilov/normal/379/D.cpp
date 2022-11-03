//#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

struct Block {
    char first, last;
    int64 inside;
    string str;
};

const char letters[] = {'A', 'C', 'X'};
const int C = 3;

vector<Block> GenerateBlocks(int len) {
    vector<Block> res;

    for (int f = 0; f<C; f++)
        for (int l = 0; l<C; l++) {
            if (len == 1 && f != l) continue;

            Block b;
            b.str = string(len, 'O');
            b.str[0] = b.first = letters[f];
            b.str[len-1] = b.last = letters[l];
            
            if (len <= 2) {
                b.inside = (len == 2 && b.str == "AC");
                res.push_back(b);
                continue;
            }
            
            b.inside = 0;
            res.push_back(b);

            int st = (b.str[0] == 'A' ? 0 : 1);
            for (; st+2<=len; st+=2) {
                b.inside++;
                b.str[st] = 'A';
                b.str[st+1] = 'C';
                if (b.first == b.str[0] && b.last == b.str[len-1])
                    res.push_back(b);
            }
        }

/*    for (int i = 0; i<res.size(); i++) {
        printf("%s = [%c %I64d %c]\n", res[i].str.c_str(), res[i].first, res[i].inside, res[i].last);
    }*/

    return res;
}

int x, n, m;
int64 k;
vector<Block> var[2];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
    scanf("%I64d%d%d%d", &k, &x, &n, &m);

    var[0] = GenerateBlocks(n);
    var[1] = GenerateBlocks(m);

    for (int i = 0; i<var[0].size(); i++)
        for (int j = 0; j<var[1].size(); j++) {
            Block sa = var[0][i], sb = var[1][j];

            Block a = sa, b = sb;
            for (int u = 1; u<k; u++) {
                Block t;
                t.first = a.first;
                t.last = b.last;
                t.inside = a.inside + b.inside + (a.last == 'A' && b.first == 'C');
//                t.str = a.str + b.str;
                a = b;
                b = t;
            }

//            printf("%s %s -> %s = %I64d\n", sa.str.c_str(), sb.str.c_str(), a.str.c_str(), a.inside);
            if (a.inside == x) {
                printf("%s\n%s\n", sa.str.c_str(), sb.str.c_str());
                return 0;
            }
        }
                   
    printf("%s\n", "Happy new year!");
	return 0;
}