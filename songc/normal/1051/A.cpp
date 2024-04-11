#include <bits/stdc++.h>
using namespace std;

char str[110];
int lo, up, di, N;

int main(){
    scanf("%d", &N);
    while (N--){
        scanf("%s", str);
        lo = up = di = 0;
        for (int i=0; str[i]; i++){
            if (islower(str[i])) lo++;
            if (isupper(str[i])) up++;
            if (isdigit(str[i])) di++;
        }
        if (!lo) {
            if (!up) str[0] = 'a', str[1] = 'A';
            else if (!di) str[0] = 'a', str[1] = '1';
            else if (up <= 1 && isupper(str[0])) str[1] = 'a';
            else if (di <= 1 && isdigit(str[0])) str[1] = 'a';
            else str[0] = 'a';
        }
        else if (!up) {
            if (!di) str[0] = 'A', str[1] = '1';
            else if (lo <= 1 && islower(str[0])) str[1] = 'A';
            else if (di <= 1 && isdigit(str[0])) str[1] = 'A';
            else str[0] = 'A';
        }
        else if (!di) {
            if (lo <= 1 && islower(str[0])) str[1] = '1';
            else if (up <= 1 && isupper(str[0])) str[1] = '1';
            else str[0] = '1';
        }
        printf("%s\n", str);
    }
    return 0;
}