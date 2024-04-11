#include <bits/stdc++.h>
using namespace std;

char s[100][100] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
char ss[100][100] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main() {
   // freopen("1.in", "r", stdin);
    int n;
    scanf("%d", &n);
    if(n <= 20) {
        printf("%s\n", s[n]);
        return 0;
    }
    int x = n / 10;
    int y = n % 10;
    printf("%s", ss[x]);
    if(y) printf("-%s", s[y]);
}