#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

char A[1010], B[1010];

bool isVowel(char ch){
    if (ch == 'a') return true;
    if (ch == 'e') return true;
    if (ch == 'i') return true;
    if (ch == 'o') return true;
    if (ch == 'u') return true;
    return false;
}

int main(){
    scanf("%s", A+1);
    scanf("%s", B+1);
    if (strlen(A+1) != strlen(B+1)){
        puts("No");
        return 0;
    }
    for (int i=1; A[i]; i++){
        if ((isVowel(A[i]) && isVowel(B[i])) || (!isVowel(A[i]) && !isVowel(B[i]))) continue;
        puts("No");
        return 0;
    }
    puts("Yes");
    return 0;
}