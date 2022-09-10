#include <bits/stdc++.h>

using namespace std;

int cnt[300];
char buff[400007];
vector<char> np;
vector<char> p;

int main() {
    int n;
    scanf("%d", &n);
    scanf(" %s", buff);

    for(int i = 0 ; i < n ; i++)
        cnt[buff[i]]++;

    int ile = 0;
    for(char c = 'a' ; c <= 'z' ; c++)
        if(cnt[c] % 2) {
            ile++;
        }
    for(char c = 'A' ; c <= 'Z' ; c++)
        if(cnt[c] % 2)
            ile++;
    for(char c = '0' ; c <= '9' ; c++)
        if(cnt[c] % 2)
            ile++;

    for(char c = 'a' ; c <= 'z' ; c++) {
        if(cnt[c] % 2)
            np.push_back(c), cnt[c]--;
        for(int i = 0 ; i < cnt[c] ; i++)
            p.push_back(c);
    }

    for(char c = 'A' ; c <= 'Z' ; c++) {
        if(cnt[c] % 2)
            np.push_back(c), cnt[c]--;
        for(int i = 0 ; i < cnt[c] ; i++)
            p.push_back(c);
    }

    for(char c = '0' ; c <= '9' ; c++) {
        if(cnt[c] % 2)
            np.push_back(c), cnt[c]--;
        for(int i = 0 ; i < cnt[c] ; i++)
            p.push_back(c);
    }

    if(ile == 0) {
        printf("1\n");
        string s = "", s2 = "";
        for(int i = 0 ; i +1< p.size() ; i+=2) {
            s += p[i];
            s2 += p[i + 1];
        }
        reverse(s2.begin(), s2.end());
        s += s2;
        printf("%s\n", s.c_str());
        return 0;
    }

    while(!((n % ile == 0) && ((n / ile) % 2 == 1)))
        ile += 2;

    printf("%d\n", ile);

    int beg = 0;
    for(int i = 0 ; i < ile ; i++) {
        string s = "";
        string s2 = "";

        for(int x = 0 ; x < n / ile / 2 ; x++) {
            s += p.back();
            p.pop_back();
            s2 += p.back();
            p.pop_back();
        }

        reverse(s2.begin(), s2.end());

        if(np.size() > 0) {
            s += np.back();
            np.pop_back();
        } else {
            s += p[beg++];
            //p.pop_back();
        }

        s += s2;

        printf("%s", s.c_str());
        if(i < ile - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}