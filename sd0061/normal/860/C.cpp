#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

set<string> ns;

set<int> E , S;
set<int> A , B;
int n;
char name[N][20];
int t[N];
int nxt[N];

int trans(char *s) {
    int x = 0;
    if (*s == '0' && strlen(s) > 1) return -1;
    while (*s) {
        if (!isdigit(*s)) {
            return -1;
        } else {
            x = x * 10 + *(s ++) - '0';
        }
    }
    if (x <= n && x > 0) {
        return x;
    } else {
        return -1;
    }
}

vector< pair<string , string> > res;

string itoa(int x) {
    static char str[10];
    sprintf(str , "%d" , x);
    return str;
}

int main() {
    scanf("%d" , &n);
    int cnt = 0;
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s%d" , name[i] , t + i);
        ns.insert(name[i]);
        cnt += t[i];
    }
    for (int i = 1 ; i <= cnt ; ++ i) {
        E.insert(i);
    }
    for (int i = cnt + 1 ; i <= n ; ++ i) {
        S.insert(i);
    }
    for (int i = 0 ; i < n ; ++ i) {
        int x = trans(name[i]);
        if (x == -1) {
            if (t[i] == 0) {
                B.insert(i);
            } else {
                A.insert(i);
            }
        } else {
            if (t[i] == 0) {
                if (x > cnt) {
                    S.erase(x);
                } else {
                    E.erase(x);
                    B.insert(~i);
                }
            } else {
                int x = trans(name[i]);
                if (x <= cnt) {
                    E.erase(x);
                } else {
                    S.erase(x);
                    A.insert(~i);
                }
            }
        }
    }

    srand(time(0));
    string odd;
    do {
        odd = "";
        for (int i = 0 ; i < 5 ; ++ i) {
            odd += 'a' + rand() % 26;
        }
    } while (ns.count(odd));

    while (!A.empty() || !B.empty()) {
        if (E.empty() && S.empty()) {
            int x;
            if (!A.empty()) {
                x = *A.begin();
                A.erase(x);
                assert(x < 0);
                x = ~x;
                S.insert(trans(name[x]));
                res.emplace_back(make_pair((string)name[x] , odd));
                A.insert(x);
                strcpy(name[x] , odd.c_str());
            } else {
                x = *B.begin();
                B.erase(x);
                assert(x < 0);
                x = ~x;
                E.insert(trans(name[x]));
                res.emplace_back(make_pair((string)name[x] , odd));
                B.insert(x);
                strcpy(name[x] , odd.c_str());
            }
        }
        while (!A.empty() && !E.empty()) {
            int x = *A.begin();
            int y = *E.begin();
            A.erase(x);
            E.erase(y);
            if (x < 0) {
                x = ~x;
                S.insert(trans(name[x]));
            }
            res.emplace_back(make_pair((string)name[x] , itoa(y)));

        }
        while (!B.empty() && !S.empty()) {
            int x = *B.begin();
            int y = *S.begin();
            B.erase(x);
            S.erase(y);

            if (x < 0) {
                x = ~x;
                E.insert(trans(name[x]));
            }
            res.emplace_back(make_pair((string)name[x] , itoa(y)));
        }
    }
    printf("%u\n" , res.size());
    for (auto &it : res) {
        printf("move %s %s\n" , it.first.c_str() , it.second.c_str());
    }
}