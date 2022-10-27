#include <iostream>
#include <cstring>
using namespace std;
char s1[12], s2[12]; 
int main() {
    scanf("%s %s", s1+1, s2+1);
    int l1 = strlen(s1+1);
    int l2 = strlen(s2+1);
    for (int i = 2; i <= l1; i ++) {
        if (s1[i] >= s2[1]) {
            for (int p=1;p<i;p++)
                printf("%c", s1[p]);
            printf("%c\n", s2[1]);
            return 0;
        }
    }

    for (int p=1;p<=l1;p++)
        printf("%c", s1[p]);
    printf("%c\n", s2[1]);    
}