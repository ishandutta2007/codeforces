#include<bits/stdc++.h>
using namespace std;

vector <char *> v;
char s[111111][50];
int d[111111];

int main()
{
    int n, i, t, j;
    scanf("%d", &n);
    for(i = 0; i < n; i ++) d[i] = 0;
    for(i = 0; i < n; i ++) {
        scanf("%s", s[i]);
        t = 0;
        for(j = 0; j < v.size(); j ++) {
            if(strcmp(s[i], v[j]) == 0) {
                    printf("%s%d\n", s[i], d[j]);
                    t = 1;
                    d[j] ++;
                    break;
            }
        }
        if(t == 0) {
                printf("OK\n");
                v.push_back(s[i]);
                d[v.size() - 1] ++;
        }
    }
}