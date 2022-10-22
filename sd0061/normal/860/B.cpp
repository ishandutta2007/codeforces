#include <bits/stdc++.h>
using namespace std;

const int N = 70005;
map<unsigned , int> h;

int n;
char str[N];

unsigned res[N];
int len[N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        /*for (int j = 0 ; j < 9 ; ++ j) str[j] = '0' + rand() % 10;
          cout << str << endl;*/
        for (int j = 0 ; j < 9 ; ++ j) {
            unsigned x = 1;
            for (int k = j ; k < 9 ; ++ k) {
                x = x * 10u + unsigned(str[k] - '0');
                if (!h.count(x)) {
                    h[x] = i;
                } else if (h[x] != i) {
                    h[x] = -1;
                }
            }
            //cout << x << endl;
        }
        len[i] = 11;
    }

    for (auto &it : h) {
        if (!~it.second) continue;
        sprintf(str , "%u" , it.first);
        int l = strlen(str);
        //cout << it.first << ' ' << it.second << endl;
        if (l < len[it.second]) {
            len[it.second] = l;
            res[it.second] = it.first;
        }
    }
    for (int i = 0 ; i < n ; ++ i) {
        //cout << res[i] << endl;
        sprintf(str , "%u" , res[i]);
        printf("%s\n" , str + 1);
    }
}