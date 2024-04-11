#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
int cnt;

int main(){
    char ch;
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        scanf(" %c", &ch);
        if (ch == '('){
            cnt++;
            printf("%d", cnt&1);
        }
        else{
            printf("%d", cnt&1);
            cnt--;
        }
    }
    return 0;
}