#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 20;

char s[N];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b, ab, ba;
        scanf("%d%d%d%d", &a, &b, &ab, &ba);
        int cnta = a + ab + ba, cntb = b + ab + ba;
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        for(int i = 1; i <= n; i++)
            if(s[i] == 'A')cnta--;
            else cntb--;
        if(cnta || cntb) {
            puts("NO");
            continue;
        }
        cnta = ab, cntb = ba;
        int useab = 0;
        vector<int> usea, useb;
        usea.clear(), useb.clear();
        for(int i = 1; i <= n; i++) {
            int j = i;
            while(j < n && s[j + 1] != s[j])j++;
            if((j - i + 1) & 1)useab += (j - i) / 2;
            else {
                if(s[i] == 'A')usea.push_back((j - i + 1) / 2);
                else useb.push_back((j - i + 1) / 2);
            }
            i = j;
        }
        sort(usea.begin(), usea.end());
        sort(useb.begin(), useb.end());
        for(int i = 0; i < usea.size() && cnta > 0; i++) {
            if(cnta >= usea[i]) {
                cnta -= usea[i];
                usea[i] = 0;
            }
            else {
                usea[i] -= cnta;
                cnta = 0;
            }
        }
        int resta = 0;
        for(int i = 0; i < usea.size(); i++)
            if(usea[i] > 0)resta += usea[i] - 1;
        
        for(int i = 0; i < useb.size() && cntb > 0; i++) {
            if(cntb >= useb[i]) {
                cntb -= useb[i];
                useb[i] = 0;
            }
            else {
                useb[i] -= cntb;
                cntb = 0;
            }
        }
        int restb = 0;
        for(int i = 0; i < useb.size(); i++)
            if(useb[i] > 0)restb += useb[i] - 1;
        if(cnta > 0 && cntb > 0) {
            if(cnta + cntb > useab) {
                puts("NO");
                continue;
            }
        }
        else if(cnta > 0) {
            if(cnta > restb + useab) {
                puts("NO");
                continue;
            }
        }
        else if(cntb > 0) {
            if(cntb > resta + useab) {
                puts("NO");
                continue;
            }
        }
        puts("YES");
    }
}