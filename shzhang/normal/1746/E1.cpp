#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n;

bool query(vector<int>& S)
{
    printf("? ");
    printf("%d ", (int)S.size());
    for (int i = 0; i < S.size(); i++) {
        printf("%d ", S[i]);
    }
    printf("\n");
    fflush(stdout);
    char result[10];
    scanf("%s", result);
    return result[0] == 'Y';
}

int main()
{
    scanf("%d", &n);
    vector<int> remain;
    for (int i = 1; i <= n; i++) remain.push_back(i);
    while (remain.size() > 3) {
        //set<int> grp[4];
        vector<int> qry1, qry2;
        for (int i = 0; i < remain.size(); i++) {
            if (i % 4 == 0) {
                qry1.push_back(remain[i]);
            } else if (i % 4 == 1) {
                qry2.push_back(remain[i]);
            } else if (i % 4 == 2) {
                qry1.push_back(remain[i]);
                qry2.push_back(remain[i]);
            }
        }
        bool res1 = query(qry1);
        bool res2 = query(qry2);
        vector<int> remain2;
        for (int i = 0; i < remain.size(); i++) {
            if (i % 4 == 0) {
                if (res1 || !res2) remain2.push_back(remain[i]);
            } else if (i % 4 == 1) {
                if (!res1 || res2) remain2.push_back(remain[i]);
            } else if (i % 4 == 2) {
                if (res1 || res2) remain2.push_back(remain[i]);
            } else {
                if (!res1 || !res2) remain2.push_back(remain[i]);
            }
        }
        remain = remain2;
    }
    if (remain.size() == 3) {
        vector<int> qry1, qry2;
        vector<int> remain2;
        qry1.push_back(remain[0]);
        qry2.push_back(remain[1]);
        if (query(qry1)) {
            if (query(qry2)) {
                remain2.push_back(remain[0]);
                remain2.push_back(remain[1]);
            } else {
                remain2.push_back(remain[0]);
                remain2.push_back(remain[2]);
            }
        } else {
            if (query(qry1)) {
                if (query(qry2)) {
                    remain2.push_back(remain[0]);
                    remain2.push_back(remain[1]);
                } else {
                    remain2.push_back(remain[0]);
                    remain2.push_back(remain[2]);
                }
            } else {
                remain2.push_back(remain[1]);
                remain2.push_back(remain[2]);
            }
        }
        remain = remain2;
    }
    for (int i = 0; i < remain.size(); i++) {
        printf("! %d\n", remain[i]);
        fflush(stdout);
        char res[5]; scanf("%s", res);
        if (res[1] == ')') return 0;
    }
    return 0;
}