#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
//
using namespace std;

#define ll long long

int n;

char ans[55];

vector<const char *> searches;

int query(const char* str)
{
    if (strlen(str) == 2 || strlen(str) == 3) searches.push_back(str);
    printf("? %s\n", str);
    fflush(stdout);
    int k;
    scanf("%d", &k);
    if (k == -1) exit(0);
    for (int i = 1; i <= k; i++) {
        int idx;
        scanf("%d", &idx);
        int cur = 0;
        while (str[cur]) {
            ans[idx] = str[cur]; idx++; cur++;
        }
    }
    return k;
}

char conv[] = {'C', 'H', 'O'};

void search_remaining(void)
{
    vector<char *> possible;
    for (int a = 0; a < 3; a++) {
        if (ans[1] && conv[a] != ans[1]) continue;
        for (int b = 0; b < 3; b++) {
            if (ans[2] && conv[b] != ans[2]) continue;
            for (int c = 0; c < 3; c++) {
                if (ans[3] && conv[c] != ans[3]) continue;
                for (int d = 0; d < 3; d++) {
                    if (ans[4] && conv[d] != ans[4]) continue;
                    char* curguess = new char[6];
                    curguess[1] = conv[a];
                    curguess[2] = conv[b];
                    curguess[3] = conv[c];
                    curguess[4] = conv[d];
                    curguess[5] = '\0';
                    bool good = true;
                    for (int x = 0; x < searches.size(); x++) {
                        if (searches[x][2]) {
                            for (int y = 1; y <= 2; y++) {
                                if (curguess[y] == searches[x][0] &&
                                    curguess[y+1] == searches[x][1] &&
                                    curguess[y+2] == searches[x][2] &&
                                    (!ans[y] || !ans[y+1] || !ans[y+2])) {
                                    good = false;
                                }
                            }
                        } else {
                            for (int y = 1; y <= 3; y++) {
                                if (curguess[y] == searches[x][0] &&
                                    curguess[y+1] == searches[x][1] &&
                                    (!ans[y] || !ans[y+1])) {
                                    good = false;
                                }
                            }
                        }
                    }
                    if (!good) continue;
                    possible.push_back(curguess);
                }
            }
        }
    }
    for (int i = 0; i + 1 < possible.size(); i++) {
        if (query(possible[i] + 1)) {
            for (int j = 1; j <= 4; j++) {
                ans[j] = possible[i][j];
            }
            return;
        }
    }
    for (int i = 1; i <= 4; i++) {
        ans[i] = possible[possible.size() - 1][i];
    }
}

void work_4(void)
{
    if (query("CH")) {search_remaining(); return;}
    if (query("CC")) {search_remaining(); return;}
    if (query("CO")) {search_remaining(); return;}
    if (query("OH")) {search_remaining(); return;}
    query("HHH");
    query("OOO");
    search_remaining();
}

void work_other(void)
{
    query("CC"); query("CH"); query("CO");
    query("OH"); query("HH");
    for (int i = 2; i < n; i++) {
        if (!ans[i]) ans[i] = 'O';
    }
    bool ans1_known = (ans[1] != '\0');
    bool ansn_known = (ans[n] != '\0');
    if (!ans1_known) {ans[1] = 'H';} if (!ansn_known) {ans[n] = 'C';}
    if (query(ans + 1)) return;
    if (!ans1_known) {ans[1] = 'H';} if (!ansn_known) {ans[n] = 'O';}
    if (query(ans + 1)) return;
    if (!ans1_known) {ans[1] = 'O';} if (!ansn_known) {ans[n] = 'C';}
    if (query(ans + 1)) return;
    if (!ans1_known) {ans[1] = 'O';} if (!ansn_known) {ans[n] = 'O';}
}

void work(void)
{
    scanf("%d", &n);
    searches.clear();
    for (int i = 0; i < 55; i++) ans[i] = '\0';
    if (n == 4) {
        work_4();
    } else {
        work_other();
    }
    printf("! %s\n", ans+1);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if (!res) exit(0);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}