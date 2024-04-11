#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

const int MAXN = 100500;

char s1[MAXN], s2[MAXN];
int val1[MAXN], val2[MAXN];
int nv[MAXN];

void
convert(int *arr, int &len)
{
    memset(nv, -1, MAXN * sizeof(nv[0]));
    for (int i = len - 1; i >= 0; --i) {
        if (arr[i] == 1 && arr[i + 1] == 0) {
            nv[i] = (arr[i + 2] == 1) ? nv[i + 2] : i + 1;
        } else if (arr[i] == 1 && arr[i + 1] == 1) {
            int go = nv[i + 1];
            for (int j = i; j < go; ++j) {
                arr[j] = 0;
            }
            arr[go] = 1;
            len = max(len, go + 1);
        }
    }
    /*for (int i = 0; i < len; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");*/
}

int
main()
{
    scanf(" %s %s", s1, s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    for (int i = len1 - 1; i >= 0; --i) {
        val1[len1 - i - 1] = s1[i] - '0';
    }
    for (int i = len2 - 1; i >= 0; --i) {
        val2[len2 - i - 1] = s2[i] - '0';
    }
    convert(val1, len1);
    convert(val2, len2);
    int vl = max(len1, len2);
    int compareTo = 0;
    for (int i = vl - 1; i >= 0; --i) {
        if (val1[i] > val2[i]) {
            compareTo = 1;
            break;
        } else if (val1[i] < val2[i]) {
            compareTo = -1;
            break;
        }
    }
    map< int, char > syms = {{-1, '<'}, {0, '='}, {1, '>'}};
    printf("%c\n", syms[compareTo]);
    return 0;
}